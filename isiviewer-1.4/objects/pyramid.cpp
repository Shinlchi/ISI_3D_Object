#include "pyramid.h"



Pyramid::Pyramid()
  : TriMesh()
{
  _name = "Pyramid";

  static const GLfloat ps[5][3] = {
    {-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},
    {0,0,1}
  };
  static const GLint ts[6][3] = {
    {0,1,2},{0,2,3},    // bottom triangles
    {0,3,4},{3,2,4},{2,1,4},{1,0,4} // side triangles
  };

  int i;

  for (i=0; i<5 ; ++i)
    this->addVertex(ps[i][0], ps[i][1], ps[i][2]);

  for (i=0; i<6; ++i)
    this->addTriangle(ts[i][0], ts[i][1], ts[i][2]);

  computeNormalsT();
  computeNormalsV(70);
}

