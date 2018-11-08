/**
 * @author Gullaume Bolzonella Daniel Pham
 * @date   October 2018
 *
 *  draw a complex 3D form by parsing an -off file
 *
 */

#ifndef     _OFF_LOADER_H_
#define     _OFF_LOADER_H_

#include "triMesh.h"
#include <fstream>
/** 
 * Function object
 *
 */
class OffLoader : public TriMesh {

public:
    OffLoader(string off);
    virtual ~OffLoader();
private:
    GLfloat **v;
    GLfloat **t;

};

#endif




