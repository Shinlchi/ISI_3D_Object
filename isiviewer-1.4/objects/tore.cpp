#include "tore.h"

Tore::Tore(int nVertice)
    : TriMesh()
{
    _name = "Tore";
    int i;
    int j;
    float x;
    float y;
    float z;
    float u; // u [0;2PI]
    float v; // v [0;2PI]
    float R = 0.75;
    float r = 0.25;

    //fill vertice vector

    for (j=0; j<nVertice; j++)
    {
        u = (2.0 * PI / (nVertice))*j;
        for (i=0; i<nVertice ; ++i)
        {
            v = ((2.0 * PI) / (nVertice))*i;
            x = (R + r * cos(v)) * cos(u);
            y = (R + r * cos(v)) * sin(u);
            z = r * sin(v);
            this->addVertex(x,y,z);
        }
    }

    //fill triangle vector
    for (i=0; i<nVertice*(nVertice-1); i++)
    {
        if ((i+1)%nVertice==0)  // example if i=39
        {
            this->addTriangle(i, i+nVertice, i+1-nVertice); // then pick vertex: (39,59,20)
            this->addTriangle(i+nVertice, i+1, i+1-nVertice); // and pick vertex: (59, 40, 20)
        }
        else //example if i=0
        {
            this->addTriangle(i, i+nVertice, i+1); // then pick vertex: (0, 20, 1)
            this->addTriangle(i+nVertice, i+nVertice+1, i+1); // and vertex (20, 21, 1)
        }
    }
    for (i=nVertice*(nVertice-1); i<nVertice*nVertice; i++)
    {
        if ((i+1)%nVertice==0)  // example if i=399
        {
           this->addTriangle(i, i-(nVertice*(nVertice-1)), i+1-nVertice); // then pick vertex: (399,19,380)
            this->addTriangle(i-(nVertice*(nVertice-1)), i+1-(nVertice*nVertice), i+1-nVertice); // and pick vertex: (19, 0, 380)
        }
        else //example if i=380
        {
            this->addTriangle(i, i-(nVertice*(nVertice-1)), i+1); // then pick vertex: (380, 0, 381)
            this->addTriangle(i-(nVertice*(nVertice-1)), i-(nVertice*(nVertice-1))+1, i+1); // and vertex (0, 1, 381)
        }
    }
    normalize();
    computeNormalsT();
    computeNormalsV(70);
}




