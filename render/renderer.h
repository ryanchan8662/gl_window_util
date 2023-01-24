//
// Created by Ryan Chan on 2023-01-23.
//

#ifndef IMPORTS
#define IMPORTS

#include "../imports.h"

#endif /* IMPORTS */

#ifndef GL_WINDOW_UTIL_RENDERER_H
#define GL_WINDOW_UTIL_RENDERER_H

class Renderer {

private:
    std::vector<GLuint> objects;
    std::vector<glm::mat4x4> transforms;

public:
    Renderer() = default;
    ~Renderer() = default;
    virtual void add_object() = 0;
    virtual void transform() = 0;
    virtual void remove_object() = 0;

};

#endif //GL_WINDOW_UTIL_RENDERER_H
