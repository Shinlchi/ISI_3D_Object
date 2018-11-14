/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  Defines a 3D disk
 *
 */

#ifndef     _DISK_HOLE_H_
#define     _DISK_HOLE_H_

#include "triMesh.h"

/** 
 * Disk_hole object
 *
 */
class Disk_hole : public TriMesh {

public:
  Disk_hole(int nVertice);
  virtual ~Disk_hole(){};


};

#endif

