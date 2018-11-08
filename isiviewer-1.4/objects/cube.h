/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D cube
 *
 */
#ifndef  _CUBE_H_
#define  _CUBE_H_

#include "triMesh.h"

/**
 * Cube Object
 *
 */
class Cube : public TriMesh {
public:
  Cube();
  virtual ~Cube(){};

};

#endif
