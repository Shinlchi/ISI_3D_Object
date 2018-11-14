#include "cone.h"

Cone::Cone(int nVertice)
    : TriMesh()
{
    _name = "Cone";
    int i;
    float x;
    float y;
    float z;

    //fill vertice vector
    this->addVertex(0,0,-1); //bottom center vertex
    for (i=0; i<nVertice ; ++i)
    {
        x = cos((i*PI)/((float)nVertice/2));
        y = sin((i*PI)/((float)nVertice/2));
        z = -1;
        this->addVertex(x,y,z);
    }
    this->addVertex(0,0,1); //top center vertex

    //fill triangle vector for the bottom
    for (i=0; i<nVertice; ++i)
    {
        if (i==nVertice-1) // example: if i=19
        {
            this->addTriangle(0, i+2-nVertice, i+1); // pick (bottomCenterVertex, 20, 1)
        }
        else //example if i=0
        {
            this->addTriangle(0, i+2, i+1); // pick (bottomCenterVertex, 2, 1)
        }
    }

    //fill triangle vector for the side
    for (i=0; i<nVertice; i++)
    {
        if ((i+1)%nVertice==0) // example: if i=19
        {
            this->addTriangle(i+1, i+2-nVertice, nVertice+1); // pick (20, 1, topVertex)
        }
        else //example if i= 0
        {
            this->addTriangle(i+1, i+2, nVertice+1); // pick (1,2,topVertex)
        }
    }

    computeNormalsT();
    computeNormalsV(70);
}


