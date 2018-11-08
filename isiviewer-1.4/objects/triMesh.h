/**
 * @author Bruno Jobard
 * fixed by Guillaume Bolzonella Daniel Pham
 * @date   Oct 2018
 *
 *  Defines 3D triangular mesh
 *
 *
 */
#ifndef  _TRIMESH_H_
#define  _TRIMESH_H_

#include <sstream>

#include "../my_object3d.h"

typedef glm::vec3  Vertex;
typedef glm::vec3  Normal;
typedef std::vector<int> Triangle;


using namespace std;
/** 
 * Simple Triangular Mesh Object
 *
 */
class TriMesh : public Object3D {

protected:
  std::vector<Vertex>   _vertices;
  std::vector<Triangle> _triangles;
  std::vector<Normal>   _normalsT;
  std::vector<Normal>   _normalsV;

public:
  TriMesh();
  virtual ~TriMesh(){};

  /**
   * draws the 3D object
   * @param flipnormals specifies if normals are flipped (default is false, the triangles are counter clock-wise)
   */
  virtual void draw(bool flipnormals=false);

  /**
   * draws the normals as line segments
   * @param flipnormals specifies if normals are flipped (default is false, the triangles are counter clock-wise)
   */
  virtual void drawNormals(bool flipnormals=false);

  /**
   * draws the vertices as points
   */
  virtual void drawVertices();

  /**
   * adds a vertex to the mesh
   * @param v the vertex to be added
   */
  void addVertex(Vertex v);

  /**
   * adds a vertex to the mesh
   * @param x the x coordinate of the vertex to be added
   * @param y the y coordinate of the vertex to be added
   * @param z the z coordinate of the vertex to be added
   */
  void addVertex(double x, double y, double z);

  /**
   * adds a triangle to the mesh
   * @param t the triangle to be added
   */
  void addTriangle(Triangle t);

  /**
   * adds a triangle to the mesh
   * @param v1 first vertex of the triangle
   * @param v2 second vertex of the triangle
   * @param v3 third vertex of the triangle
   */
  void addTriangle(int v1, int v2, int v3);

  /**
   * adds a triangle normal to the mesh
   * @param n the normal to be added
   */
  void addNormalT(Normal n);

  /**
   * adds a vertex normal to the mesh
   * @param n the normal to be added
   */
  void addNormalV(Normal n);

  /**
   * gets a vertex
   * @param index the index of the vertex
   */
  Vertex getVertex(int index);


  virtual std::string toString();
  virtual void toOStream(std::ostream& out=std::cout) const;

  /**
   * updates the bouding box of the object
   */
  void computeBoundingBox();

  /**
   * computes the triangles normals of the 3D mesh
   */
  void computeNormalsT();

  /**
   * computes the vertices normals of the 3D mesh.
   *
   * it requires triangles normals to be computed first
   * @see computeNormalsT
   * @param threshold the angles beyond which two faces are considered to have a sharp edge
   */
  void computeNormalsV(float threshold=70.);

  /**
   * scales and centers the objects so it fits in the [-1:1]^3
   * @return the scaling factor
   */
  double normalize();


};


#endif
