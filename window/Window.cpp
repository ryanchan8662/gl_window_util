//
// Created by Ryan Chan on 2023-01-16.
//

#include "Window.h"

void Window::orbit_conversion (const InputStates* data) {

    /*
    struct InputStates {
        glm::vec2 mouse_xy; glm::vec2 scroll_xy; // mouse and scroll positions

        GLuint* selection; int selection_size; // cursor selection vector

        long m_down; long k_down; // keydowns
    };
    */

    orbit_state[0] += data->scroll_xy[0] * SCROLL_SENSITIVITY_SCALING_FACTOR;
    orbit_state[1] += data->scroll_xy[1] * SCROLL_SENSITIVITY_SCALING_FACTOR;

    // set limits for vertical orbits
    orbit_state[1] = orbit_state[1] > 90.0f ? 90.0f : orbit_state[1];
    orbit_state[1] = orbit_state[1] < -90.0f ? -90.0f : orbit_state[1];

    glRotatef(orbit_state[1], 1.0f, 0.0f, 0.0f);
    glRotatef(orbit_state[0], 0.0f, 1.0f, .0f);


}

Window::Window(int x, int y, const char* title) : x(x), y(y), title(title) {
    window = nullptr;
}

Window::~Window() = default;

int Window::window_init() {

    if (window) {
        std::cerr << "window context already created." << std::endl;
        return (1);
    }

    if (!glfwInit()) {
        std::cerr << "GLFW could not be initialised." << std::endl;
        return (1);
    }

    window = glfwCreateWindow(x, y, title, nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        std::cerr << "window could not be created." << std::endl;
        return (1);
    }

    glfwMakeContextCurrent(window);


    auto input_handler = Event_handler();
    // static handlers shoot data back to a non-static context for all static/nonstatic conversion within same class
    glfwSetCursorPosCallback(window, Event_handler::cursor_callback);
    glfwSetScrollCallback(window, Event_handler::scroll_callback);
    glfwSetKeyCallback(window, Event_handler::keyboard_callback);

    //glEnable(GL_DEPTH_TEST);
    glClearColor(0.12f, 0.11f, 0.1f, 1.0f);

    while (!glfwWindowShouldClose(window)) {

        glfwWaitEvents();
        //std::cout << "Event triggered" << std::endl;

        glPushMatrix(); // push stack for view transformations
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // process user input for current event
        // retrieve mouse data and scale with conversion handler
        orbit_conversion(input_handler.input_data());

        glPushMatrix(); // push stack for model transformations

        glColor3f(0.75f, 0.75f, 0.75f);

        glBegin(GL_TRIANGLES);

            glVertex3f(0.0f, 0.7f, 0.0f);
            glVertex3f(-0.75f, -0.3f, 0.0f);
            glVertex3f(0.75f, -0.3f, 0.0f);

        glEnd();

        glColor3f(0.0f, 1.0f, 0.0f);
        glPointSize(10.0f);

        glBegin(GL_POINTS);

            glVertex3f(0.0f, 0.0f, 0.3f);
            glVertex3f(0.0f, 0.0f, -0.3f);

        glEnd();
        // draw();

        glPopMatrix(); // model transformations

        glPopMatrix(); // view transformations

        glfwSwapBuffers(window); // complete draw call
    }

    glfwTerminate();
    return (0);
}
