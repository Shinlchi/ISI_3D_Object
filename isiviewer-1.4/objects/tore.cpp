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
    float R = 0.95;
    float r = 0.25;

    //fill vertice vector
    if ( 1) // to fill the square [-1, 1]^3, the equation R+r must be equal to 1
    {
        for (j=0; j<nVertice; j++)
        {
            u = (2.0 * PI / (nVertice-1))*j;
            for (i=0; i<nVertice ; ++i)
            {
                v = ((2.0 * PI) / (nVertice-1))*i;
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

        normalize();
        computeNormalsT();
        computeNormalsV();  // to be fixed
    }

}


