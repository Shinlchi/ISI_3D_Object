/**
 * @file   my_scene.h
 * @author Bruno Jobard
 * @author Author1
 * @author Author2
 * @date   Sep 2009
 *
 * @brief  Defines a custom 3D scene
 *
 *
 */
#ifndef _ISI_MY_SCENE_H_
#define _ISI_MY_SCENE_H_

#include <QObject>
#include <QKeyEvent>
#include "my_object3d.h"


class MyScene : public QObject
{
  Q_OBJECT

  enum displayModeType {WIREFRAME=1, SMOOTH=2, NORMALS=4};

protected:
  std::vector<Object3D*> _objects; /**< all 3D objects */

  // Parameters
  int   _currentObject;    /**< id of the current displayed 3D object */
  float _radius;           /**< radius of the object in the rendering window */
  int   _displayMode;	   /**< current display mode */
  bool  _normalsFlipped;   /**< flip triangle normals? */
  bool  _displayWireframe; /**< display the triangle mesh in wireframe? */

  // Info for GUI
  double _radiusMin;
  double _radiusMax;
  double _radiusIncr;

public:
  MyScene(float radius=1.);
  virtual ~MyScene();

  inline void setCurrentObject(int co){_currentObject=co;}
  inline int  currentObject(){return _currentObject;}
  inline void setDisplayMode(int dm){_displayMode=dm;}
  inline int  displayMode(){return _displayMode;}

  inline void   setRadius(float radius){_radius=radius;}
  inline float  radius(){return _radius;}
  inline double radiusMin (){return _radiusMin;}
  inline double radiusMax (){return _radiusMax;}
  inline double radiusIncr(){return _radiusIncr;}

  void init();
  void draw();

  void addObject(Object3D*);

  // Qt signals for interacting with the graphical interface
signals:
  void sigCurrentObjectChanged(int co);
  void sigDisplayModeChanged(int dm);
  void sigRadiusChanged(double radius);
  void sigWireframeChanged(bool on);
  void sigSmoothChanged(bool on);
  void sigDisplayNormalsChanged(bool on);
  void sigFlipNormalsChanged(bool on);

  // Qt slots for interacting with the graphical interface
public slots:
  void slotSetCurrentObject(int co);
  void slotSetDisplayMode(int dm);
  void slotSetRadius(double radius);
  void slotSetWireframe(bool on);
  void slotSetSmooth(bool on);
  void slotSetDisplayNormals(bool on);
  void slotSetFlipNormals(bool on);

public:
  bool keyPressEvent(QKeyEvent *e);

};


#endif
