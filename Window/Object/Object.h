//
// Created by Ryan Chan on 2023-01-16.
//

#ifndef STRING
#define STRING

#include <string>

#endif /* STRING */

#ifndef GLM
#define GLM

#include <glm/glm.hpp>

#endif /* GLM */

#ifndef VECTOR
#define VECTOR

#include <vector>

#endif /* VECTOR */

#ifndef GL_WINDOW_UTIL_OBJECT_H
#define GL_WINDOW_UTIL_OBJECT_H

enum ObjectTypes { POINT, LINE, TRI_MESH, POLY_MESH };

struct Object {
    std::string object_name;
    glm::mat4x4 object_transforms;
    glm::vec3 object_colour;
    ObjectTypes object_type;
};




#endif //GL_WINDOW_UTIL_OBJECT_H
