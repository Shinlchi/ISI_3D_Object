#include "off_loader.h"



OffLoader::OffLoader(string off)
    : TriMesh()
{
    _name = "off_lader";

    int vertex = 0;
    int faces = 0;
    int edge = 0;
    double x;
    double y;
    double z;
    double nb_vertice;
    double indice;

    ifstream obj_off(off.c_str());
    if(obj_off) //ready for parsing
    {
        string ligne;
        getline(obj_off, ligne);
        obj_off >> vertex;
        obj_off >> faces;
        obj_off >> edge;

        GLint t[faces][3];

        //fill vertex
        for (int i=0;i<vertex;i++){
            obj_off >> x;
            obj_off >> y;
            obj_off >> z;
            addVertex(x,y,z);
        }

        for (int i=0;i<faces;i++){
            obj_off >> nb_vertice;
            if (nb_vertice >= 4)
            {
                cout << "one of those polygone is not a triangle" << endl;
                exit (-1);
            }
            else
            {
                for (int k=0;k<3;k++)
                {
                    double n;
                    obj_off >> n; //read the k double
                    if (k==0)t[i][0] = n;
                    if (k==1)t[i][1] = n;
                    if (k==2)t[i][2] = n;
                }
            }
//            for(int k=0; k<nb_vertice-2; k++)
//            {
//                obj_off >> indice;
//                addTriangle(indice,);
//            }
        }

        // Fill triangles vector
        for (int i=0; i<faces; ++i)
            this->addTriangle(t[i][0], t[i][1], t[i][2]);
    }
    else
    {
        cout << "Error file : can't read the file" << endl;
        exit(0);
    }
    obj_off.close(); //close file

    normalize();
    computeNormalsT();
    computeNormalsV(70);
}

OffLoader::~OffLoader()
{
    for (int i=0; i <_triangles.size(); i++)
    {
        delete[] t[i];
    }
    delete[] t;
}

