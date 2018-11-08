/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  Defines a 3D disk
 *
 */

#ifndef     _DISK_H_
#define     _DISK_H_

#include "triMesh.h"

/** 
 * Disk object
 *
 */
class Disk : public TriMesh {

public:
  Disk(int nVertice);
  virtual ~Disk(){};


};

#endif

