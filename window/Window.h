//
// Created by Ryan on 2023-01-16.
//

#ifndef IMPORTS
#define IMPORTS

#include "../imports.h"

#endif /* IMPORTS */

#ifndef EVENTHANDLER
#define EVENTHANDLER

#include "Event_handler.h"

#endif /* EVENTHANDLER */

#ifndef GL_WINDOW_UTIL_WINDOW_H
#define GL_WINDOW_UTIL_WINDOW_H

#define SCROLL_SENSITIVITY_SCALING_FACTOR 1.0f

class Window {

private:
    GLFWwindow* window;
    int x, y;
    const char* title;
    glm::vec2 orbit_state{};

    void orbit_conversion(const InputStates* data);

public:
    Window(int x, int y, const char* title);
    ~Window();
    int window_init();

};


#endif //GL_WINDOW_UTIL_WINDOW_H
