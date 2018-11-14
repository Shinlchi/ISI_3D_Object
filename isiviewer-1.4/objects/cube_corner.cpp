#include "cube_corner.h"

Cube_corner::Cube_corner()
    : TriMesh()
{
    _name = "Cube_corner";

    // vertex coordinates
    static const GLfloat v[14][3] = {
        {-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},
        {-1,-1, 1},{-1,1, 1},{1,1, 1},{1,-1, 1},{0,1,1},{1,0,1},{0,0,1},{1,1,0},{1,0,0},{0,1,0},
    };

    // triangles vertex indices
    static const GLint t[19][3] = {
        {1,2,0},{3,0,2},  // bottom triangles
        {1,5,2},{5,8,13},{8,11,13},{11,2,13},{2,7,3},{2,11,12},{11,9,12},{9,7,12},{3,7,0},{0,7,4},{0,4,1},{1,4,5},    // side triangles
        {4,7,5},{5,10,8},{8,10,9},{9,10,7},   // top triangles
        {8,9,11}, // corner
    };

    //--- Fill vertices and triangles vectors

    // Fill vertices vector
    for (int i=0; i<14 ; ++i)
        this->addVertex(v[i][0], v[i][1], v[i][2]);

    // Fill triangles vector
    for (int i=0; i<19; ++i)
        this->addTriangle(t[i][0], t[i][1], t[i][2]);

    // Fill normals vectors
    computeNormalsT();
    computeNormalsV(70);
}

