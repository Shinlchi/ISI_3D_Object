/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  Defines a 3D tore
 *
 */
#ifndef     _TORE_H_
#define     _TORE_H_

#include "triMesh.h"

/** 
 * Tore object
 *
 */
class Tore : public TriMesh {

public:
  Tore(int nVertice);
  virtual ~Tore(){};


};

#endif


