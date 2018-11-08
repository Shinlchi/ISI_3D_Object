/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  Defines a 3D sphere
 *
 */

#ifndef     _SPHERE_H_
#define     _SPHERE_H_

#include "triMesh.h"

/** 
 * Sphere object
 *
 */
class Sphere : public TriMesh {

public:
  Sphere(int nVertice);
  virtual ~Sphere(){};


};

#endif

