/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  Defines a 3D cone
 *
 */

#ifndef     _CONE_H_
#define     _CONE_H_

#include "triMesh.h"

/** 
 * Cone object
 *
 */
class Cone : public TriMesh {

public:
  Cone(int nVertice);
  virtual ~Cone(){};


};

#endif

