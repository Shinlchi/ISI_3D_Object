#include "cone.h"

Cone::Cone(int nVertice)
    : TriMesh()
{
    _name = "Cone";
    int i;
    int j;
    float x;
    float y;
    float z;
    float nLayer = 5; //layer

    //fill vertice vector
    this->addVertex(0,0,-1); //bottom center vertex
    for (j=0; j<nLayer-1; j++) //side vertex
    {
        z = -1 + (2.0/(nLayer-1))*j;
        for (i=0; i<nVertice ; ++i)
        {
            x = cos((i*PI)/((float)nVertice/2));
            y = sin((i*PI)/((float)nVertice/2));
            this->addVertex(x*(1-((float)j/(nLayer-1))),y*(1-((float)j/(nLayer-1))),z);
        }
    }
    this->addVertex(0,0,1); //top center vertex

    //fill triangle vector for the bottom
    for (i=0; i<nVertice; ++i)
    {
        if ((i+1) % nVertice == 0)  // example if i=19
        {
            this->addTriangle(0, i+2-nVertice, i+1); //then pick vertex: (bottomCenter,1,20)
        }
        else //example i= 0
        {
            this->addTriangle(0, i+2, i+1); // pick vertex: (bottomCenter,2,1)
        }
    }

    //fill triangle for the top
    for (i=nVertice*(nLayer-2); i<nVertice*(nLayer-1); i++)
    {
        if ((i+1) % nVertice == 0)
        {
            this->addTriangle(nVertice*(nLayer-1)+1, i+1, i+2-nVertice);
        }
        else
        {
            this->addTriangle(nVertice*(nLayer-1)+1, i+1, i+2);
        }
    }

    //fill triangle for the side
    for (i=0; i<nVertice*(nLayer-2); i++)
    {
        if ((i+1) % nVertice == 0) // example if i=19
        {
            this->addTriangle(i+1, i+2-nVertice, i+1+nVertice); // 20, 1, 40
            this->addTriangle(i+1+nVertice, i+2-nVertice, i+2); // 40, 1, 41
        }
        else //example if i= 0
        {
            this->addTriangle(i+1, i+2, i+1+nVertice); // 1,2,21
            this->addTriangle(i+1+nVertice, i+2, i+2+nVertice); //21,2,22
        }
    }

    computeNormalsT();
    computeNormalsV(70);
}

