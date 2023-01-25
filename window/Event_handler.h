//
// Created by Ryan Chan on 2023-01-19.
//

#ifndef IMPORTS
#define IMPORTS

#include "../imports.h"

#endif /* IMPORTS */

#ifndef GL_WINDOW_UTIL_EVENT_HANDLER_H
#define GL_WINDOW_UTIL_EVENT_HANDLER_H

struct InputStates {
    glm::vec2 mouse_xy; glm::vec2 scroll_xy; // mouse and scroll positions

    GLuint* selection; int selection_size; // cursor selection vector

    long m_down; long k_down; // keydowns
};

class Event_handler{

private:
    static struct InputStates* staticref_input;
    struct InputStates* input;


public:
    Event_handler();
    ~Event_handler() = default;

    // data retrieval function
    const InputStates* input_data ();

    // callback functions
    static void cursor_callback(GLFWwindow* window, double x, double y);
    static void scroll_callback(GLFWwindow* window, double x, double y);
    static void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static void reset_cursor_state();

};


#endif //GL_WINDOW_UTIL_EVENT_HANDLER_H
