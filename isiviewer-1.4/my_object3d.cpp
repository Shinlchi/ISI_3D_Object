#include "my_object3d.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <GL/glew.h>

/** 
 * Object3D Constructor
 *
 */
Object3D::Object3D()
{
  _name = "Object3D";

  _bBoxMin = glm::vec3(0,0,0);
  _bBoxMax = glm::vec3(0,0,0);
  _bBempty = true;
}

Object3D::~Object3D()
{
}

/** 
 * Print 3D object information in terminal
 *
 * @param out
 * @param obj3D
 *
 * @return
 */
std::ostream& operator << (std::ostream& out, const Object3D& obj3D)
{
  obj3D.toOStream(out);
  return out;
}
std::string Object3D::toString(){
  return "[Object3D]";
}
void Object3D::toOStream(std::ostream& out) const
{
  out << "-- " << _name;
  out<< std::endl;
}


/** 
 * Draw an Object3D
 *
 * Empty for this abstract Object3D
 */
void Object3D::draw(bool flipnormals)
{

}

void Object3D::drawNormals(bool flipnormals)
{

}


void Object3D::extendBoundingBox(glm::vec3 v)
{
  if (_bBempty) {
      _bBoxMin = _bBoxMax = v;
      _bBempty = false;
    } else {
      if(v.x>_bBoxMax.x) _bBoxMax.x=v.x;
      if(v.y>_bBoxMax.y) _bBoxMax.y=v.y;
      if(v.z>_bBoxMax.z) _bBoxMax.z=v.z;

      if(v.x<_bBoxMin.x) _bBoxMin.x=v.x;
      if(v.y<_bBoxMin.y) _bBoxMin.y=v.y;
      if(v.z<_bBoxMin.z) _bBoxMin.z=v.z;
    }
}

glm::vec3 Object3D::getBoundingBoxCenter()
{
  glm::vec3 center= _bBoxMin+_bBoxMax;
  center /= 2.0;
  return center;
}
