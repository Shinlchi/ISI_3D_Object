#include "disk.h"

Disk::Disk(int nVertice)
    : TriMesh()
{
    _name = "Disk";
    int i;
    float x;
    float y;

    //fill vertice vector
    this->addVertex(0,0,0); // center vertice
    for (i=0; i<nVertice ; ++i)
    {
        x = cos((i*PI)/((float)nVertice/2));
        y = sin((i*PI)/((float)nVertice/2));
        this->addVertex(x,y,0);
    }

    //fill triangle vector
    for (i=0; i<nVertice; ++i)
    {
        if ((i+1) % nVertice == 0)
        {
            this->addTriangle(0, i+1, i+2-nVertice);
        }
        else
        {
            this->addTriangle(0, i+1, i+2);
        }
    }

    computeNormalsT();
    computeNormalsV(70);  // to be fixed
}

