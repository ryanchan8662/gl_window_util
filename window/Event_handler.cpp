//
// Created by Ryan Chan on 2023-01-19.
//

#include "Event_handler.h"

struct InputStates* Event_handler::staticref_input = new struct InputStates;

Event_handler::Event_handler() {

    input = staticref_input;

}

const InputStates* Event_handler::input_data () {

    return (input);

}

void Event_handler::reset_cursor_state() {

    staticref_input->scroll_xy = glm::vec2(0.0f, 0.0f);

}

void Event_handler::cursor_callback(GLFWwindow* window, double x, double y) {
    //std::cout << "c_callback" << std::endl;
    staticref_input->mouse_xy = glm::vec2(x, y);
}

void Event_handler::scroll_callback(GLFWwindow* window, double x, double y) {
    //std::cout << "s_callback" << std::endl;
    staticref_input->scroll_xy = glm::vec2(x, y);
}

void Event_handler::keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS)
        std::cout << "k_callback: " << key << std::endl;
}