/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  draw curve 3D with a function
 *
 */

#ifndef     _FUNC_SURFACE_H_
#define     _FUNC_SURFACE_H_

#include "triMesh.h"

/** 
 * Function object
 *
 */
class FuncSurface : public TriMesh {

public:
    FuncSurface(int nbx, int nby, float minx, float maxx, float miny, float maxy, float (*func)(float,float));
    virtual ~FuncSurface(){};


};

#endif



