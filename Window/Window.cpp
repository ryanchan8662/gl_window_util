//
// Created by Ryan Chan on 2023-01-16.
//

#include "Window.h"


Window::Window(int x, int y, const char* title) : x(x), y(y), title(title) {
    window = nullptr;
}

Window::~Window() = default;

int Window::window_init() {

    if (window) {
        std::cerr << "Window context already created." << std::endl;
        return (1);
    }

    if (!glfwInit()) {
        std::cerr << "GLFW could not be initialised." << std::endl;
        return (1);
    }
    window = glfwCreateWindow(x, y, title, nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        std::cerr << "Window could not be created." << std::endl;
        return (1);
    }

    glfwMakeContextCurrent(window);


    auto input_handler = Event_handler();
    glfwSetCursorPosCallback(window, Event_handler::cursor_callback);
    glfwSetScrollCallback(window, Event_handler::scroll_callback);
    glfwSetKeyCallback(window, Event_handler::keyboard_callback);


    while (!glfwWindowShouldClose(window)) {

        glfwWaitEvents();
        std::cout << "Event triggered" << std::endl;

        // process user input for current event
        const InputStates* data = input_handler.input_data();
        // draw();

    }

    glfwTerminate();
    return (0);
}

void Window::process_input() {



}