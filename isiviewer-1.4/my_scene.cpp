#include "my_scene.h"

#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GL/gl.h>  // OpenGL include file

using namespace std;

/** 
 * Constructor
 *
 * @param radius
 */
MyScene::MyScene(float radius)
{
  std::cout << "constructing :  MyScene" << std::endl;

  _currentObject = 0;

  _radius = radius;

  _normalsFlipped=false;

  _radiusMin = 0.1;
  _radiusMax = 2.0;
  _radiusIncr = 0.1;

  this->slotSetDisplayMode(0);
}

/** 
 * Destructor
 *
 */
MyScene::~MyScene(){
  std::cout<<"~MyScene"<<std::endl;
}

/** 
 * Init the scene and OpenGL state
 *
 */
void MyScene::init(){

  // set antialiased lines
  //  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glEnable(GL_RESCALE_NORMAL);
  glLineWidth(1);
}

/** 
 * Draw the scene
 *
 */
void MyScene::draw()
{
  glPushMatrix();
  glScalef(_radius/2, _radius/2, _radius/2);

  //draw [-1:1]^3 bounding box
  glDisable(GL_LIGHTING);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glLineWidth(1);
  glColor3f(.5, .5, .5);
  glBegin(GL_QUAD_STRIP);
  glVertex3f(-1,-1,-1); glVertex3f(-1,-1, 1);
  glVertex3f(-1, 1,-1); glVertex3f(-1, 1, 1);
  glVertex3f( 1, 1,-1); glVertex3f( 1, 1, 1);
  glVertex3f( 1,-1,-1); glVertex3f( 1,-1, 1);
  glVertex3f(-1,-1,-1); glVertex3f(-1,-1, 1);
  glEnd();


  // Draw current object
  glEnable(GL_LIGHTING);
  glShadeModel(_displayMode&MyScene::SMOOTH ? GL_SMOOTH : GL_FLAT);
  glPolygonMode(GL_FRONT_AND_BACK, _displayMode&MyScene::WIREFRAME ? GL_LINE : GL_FILL);

  glColor3f(0.8, 0., 0.);

  glm::vec3 c=_objects[_currentObject]->getBoundingBoxCenter();
  glTranslated(-c.x,-c.y,-c.z);
  _objects[_currentObject]->draw(_normalsFlipped);

  // Draw normals
  if(_displayMode&MyScene::NORMALS)
    _objects[_currentObject]->drawNormals(_normalsFlipped);

  glPopMatrix();
}

void MyScene::slotSetWireframe(bool on){
  if(on) _displayMode|= MyScene::WIREFRAME;
  else   _displayMode&=~MyScene::WIREFRAME;

  emit sigWireframeChanged(on);
}
void MyScene::slotSetSmooth(bool on){
  if(on) _displayMode|= MyScene::SMOOTH;
  else   _displayMode&=~MyScene::SMOOTH;

  emit sigSmoothChanged(on);
}
void MyScene::slotSetDisplayNormals(bool on){
  if(on) _displayMode|= MyScene::NORMALS;
  else   _displayMode&=~MyScene::NORMALS;

  emit sigDisplayNormalsChanged(on);
}
void MyScene::slotSetFlipNormals(bool on){
  _normalsFlipped=on;
  emit sigFlipNormalsChanged(on);
}

/** 
 * Slot set current object
 *
 * @param currentObject
 */
void MyScene::slotSetCurrentObject(int currentObject)
{
  if(currentObject<0)
    _currentObject = _objects.size()-1;
  else
    _currentObject = currentObject%_objects.size();

  std::cout << dynamic_cast<const Object3D&>(*_objects.at(_currentObject)) << std::endl;
  emit sigCurrentObjectChanged(currentObject);
}

/** 
 * Slot set display mode
 *
 * @param displayMode
 */

void MyScene::slotSetDisplayMode(int displayMode)
{
  _displayMode = displayMode;
  std::cout << "slotSetDisplayMode "<< _displayMode << std::endl;

  slotSetWireframe(_displayMode&MyScene::WIREFRAME);
  slotSetSmooth(_displayMode&MyScene::SMOOTH);
  slotSetDisplayNormals(_displayMode&MyScene::NORMALS);

  emit sigDisplayModeChanged(displayMode);
}

/** 
 * Slot set radius
 *
 * @param radius
 */
void MyScene::slotSetRadius(double radius)
{
  if (fabs(_radius - float(radius))>1e-6) {
      //std::cout << "slotSetRadius "<< radius << std::endl;
      _radius = radius;
      emit sigRadiusChanged(radius);
    }
}

/** 
 * Process keyboard events for QGLViewer widget
 *
 * @param e a keyboard event from QGLViewer
 *
 * @return true if the event has been handled
 */
bool MyScene::keyPressEvent(QKeyEvent *e)
{
  float epsilon = 1e-5;  // for float comparison
  bool handled = true;

  unsigned int keyFn=0;
  switch(e->key()|e->modifiers()){
    case Qt::Key_R:
      if (_radius+_radiusIncr <= _radiusMax + epsilon)
        this->slotSetRadius(_radius+_radiusIncr);
      break;
    case Qt::Key_R|Qt::SHIFT:
      if (_radius-_radiusIncr >= _radiusMin - epsilon)
        this->slotSetRadius(_radius-_radiusIncr);
      break;
    case Qt::Key_O:
      this->slotSetCurrentObject(_currentObject+1);
      break;
    case Qt::Key_O|Qt::SHIFT:
      this->slotSetCurrentObject(_currentObject-1);
      break;

    case Qt::Key_M:
      this->slotSetDisplayMode((_displayMode+1)%8);
      break;
    case Qt::Key_S:
      this->slotSetSmooth(!(_displayMode & MyScene::SMOOTH));
      break;
    case Qt::Key_W:
      this->slotSetWireframe(!(_displayMode & MyScene::WIREFRAME));
      break;
    case Qt::Key_N:
      this->slotSetDisplayNormals(!(_displayMode & MyScene::NORMALS));
      break;

    case Qt::Key_F12: keyFn++;
    case Qt::Key_F11: keyFn++;
    case Qt::Key_F10: keyFn++;
    case Qt::Key_F9 : keyFn++;
    case Qt::Key_F8 : keyFn++;
    case Qt::Key_F7 : keyFn++;
    case Qt::Key_F6 : keyFn++;
    case Qt::Key_F5 : keyFn++;
    case Qt::Key_F4 : keyFn++;
    case Qt::Key_F3 : keyFn++;
    case Qt::Key_F2 : keyFn++;
    case Qt::Key_F1 : keyFn++;
      if(_objects.size()>=keyFn)
        this->slotSetCurrentObject(keyFn-1);
      break;

    default:
      handled=false;
    }
  return handled;
}


void MyScene::addObject(Object3D *o){
  _objects.push_back(o);
}
