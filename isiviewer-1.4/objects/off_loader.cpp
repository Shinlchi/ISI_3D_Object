#include "off_loader.h"



OffLoader::OffLoader(string off)
    : TriMesh()
{
    _name = "off_lader";

    int vertex = 0;
    int faces = 0;
    int edge = 0;

    ifstream obj_off(off.c_str());
    if(obj_off) //ready for parsing
    {
        string ligne;

        getline(obj_off, ligne);
        obj_off >> vertex;
        obj_off >> faces;
        obj_off >> edge;

        GLfloat v[vertex][3];
        GLint t[faces][3];

        //fill vertex
        for (int i=0;i<vertex;i++){
            for (int j=0;j<3;j++){
                double n;
                obj_off >> n; //read the j double
                if (j==0)v[i][0] = n;
                if (j==1)v[i][1] = n;
                if (j==2)v[i][2] = n;
            }
        }

        for (int i=0;i<faces;i++){
            double a;
            obj_off >> a;
            if (a >= 4)
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
        }
        // Fill vertices vector
        for (int i=0; i<vertex ; ++i)
            this->addVertex(v[i][0], v[i][1], v[i][2]);

        // Fill triangles vector
        for (int i=0; i<faces; ++i)
            this->addTriangle(t[i][0], t[i][1], t[i][2]);
    }
    else
    {
        cout << "can't read the file" << endl;
    }
    obj_off.close(); //close file

    normalize();
    computeNormalsT();
    computeNormalsV(70);
}

OffLoader::~OffLoader()
{
    for (int i=0; i <this->_vertices.size(); i++)
    {
        delete[] v[i];
    }
    delete[] v;
    for (int i=0; i <_triangles.size(); i++)
    {
        delete[] t[i];
    }
    delete[] t;
}

