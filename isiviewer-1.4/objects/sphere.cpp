#include "sphere.h"

Sphere::Sphere(int nVertice)
    : TriMesh()
{
    _name = "Sphere";
    int i;
    int j;
    float x;
    float y;
    float z;
    float teta; // [-PI,PI]
    float fi; //[-PI/2,PI/2]

    //fill vertice vector
    this->addVertex(0,0,-1); //bottom center vertice
    for (j=0; j<nVertice; j++) //side vertices
    {
        fi = -PI/2 + (PI/(nVertice-1))*j;
        for (i=0; i<nVertice ; ++i)
        {
            teta = -PI + ((2*PI)/(nVertice-1))*i;
            x = cos(fi) * cos(teta);
            y = cos(fi) * sin(teta);
            z = sin(fi);
            this->addVertex(x,y,z);
        }
    }
    this->addVertex(0,0,1); //top center

    //fill triangle vector for the bottom
    for (i=0; i<nVertice; ++i)
    {
        if (i==nVertice-1)
        {
            this->addTriangle(0, i+2-nVertice, i+1);
        }
        else
        {
            this->addTriangle(0, i+2, i+1);
        }
    }

    //fill triangle for the top
    for (i=nVertice*(nVertice-1); i<nVertice*nVertice; i++){
        if ((i+1) % nVertice == 0) // example if i=399
        {
            this->addTriangle(nVertice*nVertice+1, i+1, i+2-nVertice); // pick vertex: (centerTop, 400, 381)
        }
        else //example if i=380
        {
            this->addTriangle(nVertice*nVertice+1, i+1, i+2); //pick vertex: (centerTop, 381, 382)
        }
    }

    //fill triangle for the side
    for (i=0; i<nVertice*(nVertice-1); i++)
    {
        if ((i+1) % nVertice == 0)  // example if i=39
        {
            this->addTriangle(i+1, i+2-nVertice, i+1+nVertice); // then pick vertex : (40,21,60)
            this->addTriangle(i+1+nVertice, i+2-nVertice, i+2); // pick vertex: (60,21,41)
        }
        else
        {
            this->addTriangle(i+1, i+2, i+1+nVertice);
            this->addTriangle(i+1+nVertice, i+2, i+2+nVertice);
        }
    }

    computeNormalsT();
    computeNormalsV();  // to be fixed
}


