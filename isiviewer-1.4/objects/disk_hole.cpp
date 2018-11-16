#include "disk_hole.h"

Disk_hole::Disk_hole(int nVertice)
    : TriMesh()
{
    _name = "Disk_hole";
    int i;
    float x;
    float y;

    //fill vertice vector
    for (i=0; i<nVertice ; ++i)
    {
        x = cos((i*PI)/((float)nVertice/2));
        y = sin((i*PI)/((float)nVertice/2));
        this->addVertex(x,y,0);
    }
    for (i=0; i<nVertice ; ++i)
    {
        x = cos((i*PI)/((float)nVertice/2));
        y = sin((i*PI)/((float)nVertice/2));
        this->addVertex(x/2,y/2,0);
    }


    //fill triangle vector
    for (i=0; i<nVertice; ++i)
    {
        if ((i+1) % nVertice == 0)
        {
            this->addTriangle(i, i+1-nVertice, i+nVertice);
            this->addTriangle(i+1-nVertice, i+1,i+nVertice);
        }
        else
        {
            this->addTriangle(i, i+1, i+1+nVertice);
            this->addTriangle(i, i+1+nVertice, i+nVertice);
        }
    }

    computeNormalsT();
    computeNormalsV();
}

