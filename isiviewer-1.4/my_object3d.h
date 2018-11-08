/**
 * @file   my_object3d.h
 * @author Bruno Jobard
 * @author Author1
 * @author Author2
 * @date   Oct 2012
 *
 * @brief  Defines a 3D object base
 *
 *
 */
#ifndef _ISI_MY_OBJECTS_H_
#define _ISI_MY_OBJECTS_H_

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <vector>       // STL Vector type
#include <glm/glm.hpp>  // for vec3 (and other vector) type and related
// geometric operations. Look at documentation
// file: glm/doc/index.html

#ifndef PI
#    define PI 3.14159265358979323846
#endif


/** 
 * Base of a 3D object
 *
 */
class Object3D {

protected:

    std::string _name;               /**< Object name */
    glm::vec3   _bBoxMin, _bBoxMax;  /**< Bounding box corners */
    bool        _bBempty;            /**< Is the Bounding box empty? */

public:
    Object3D();
    virtual ~Object3D();

    /**
   * Set and get the name of the object
   */
    std::string getName() {return _name;}
    void setName(std::string name){_name = name;}

    /**
   * Draw the object
   */
    virtual void draw(bool flipnormals=false);

    /**
   * Draw the normals of the object
   */
    virtual void drawNormals(bool flipnormals=false);

    /**
   * Get the center of the bounding box of the object
   */
    glm::vec3 getBoundingBoxCenter();

    /**
   * Get the name of the object
   */
    virtual std::string toString();

    /**
   * Send the state of the object to an output stream
   */
    virtual void toOStream(std::ostream& out=std::cout) const;

protected:
    /**
   * Extend the bounding box of an object with the new vertex
   *
   * @param newVertex extends the bounding box if it is outside the current bounding box
   */
    void extendBoundingBox(glm::vec3 newVertex);

    friend std::ostream& operator << (std::ostream& out, const Object3D& obj3D);
};

std::ostream& operator << (std::ostream& out, const Object3D& obj3D);


#endif
