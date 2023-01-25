//
// Created by ryanc on 2023-01-24.
//

#ifndef IMPORTS
#define IMPORTS

#include "../../imports.h"

#endif /* IMPORTS */

#ifndef GL_WINDOW_UTIL_PROTOTYPE_H
#define GL_WINDOW_UTIL_PROTOTYPE_H

#include "reference.h"


class Prototype {

private:
    std::vector<glm::vec3>* vertices;
    glm::mat4x4 initial_transform;

public:
    Prototype(glm::vec3* pts, long n_pts);
    const Reference* instantiate();

};


#endif //GL_WINDOW_UTIL_PROTOTYPE_H
