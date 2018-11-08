#include "func_surface.h"

FuncSurface::FuncSurface(int nbx, int nby, float minx, float maxx, float miny, float maxy, float (*func)(float,float))
    : TriMesh()
{
    _name = "FuncSurface";

    int i;
    int j;
    float x;
    float y;
    float z;

    for (j=0; j<nbx; j++)
    {
        x = minx + j*((maxx-minx)/(nbx-1));

        for (i=0; i<nby; i++)
        {
            y = miny + i*((maxy-miny)/(nby-1));

            z = func(x,y);
            this->addVertex(x, y, z);
        }
    }

    for (i=0; i<nbx*(nby-1); i++)
    {
        if ((i+1)%nbx==0) //if i=49
        {} //do not bind the border like a sphere
        else //if i=50
        {
            this->addTriangle(i, i+nbx, i+1); // then pick vertex: (50, 100, 51)
            this->addTriangle(i+nbx, i+nbx+1, i+1); // and vertex (100, 101, 51)
        }
    }

    normalize();
    computeNormalsT();
    computeNormalsV();  // to be fixed
}
