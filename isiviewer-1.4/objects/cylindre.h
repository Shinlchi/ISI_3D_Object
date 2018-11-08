/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  Defines a 3D cylindre
 *
 */

#ifndef     _CYLINDRE_H_
#define     _CYLINDRE_H_

#include "triMesh.h"

/** 
 * Cylindre object
 *
 */
class Cylindre : public TriMesh {

public:
  Cylindre(int nVertice);
  virtual ~Cylindre(){};


};

#endif
