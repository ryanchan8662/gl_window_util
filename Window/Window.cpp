//
// Created by Ryan Chan on 2023-01-16.
//

#include "Window.h"


Window::Window() {
    window = nullptr;
    object_list = std::vector<Object*>();
}
Window::Window (const Window &in) {
    window = nullptr;
    object_list = std::vector<Object*>();
}
Window::~Window() = default;

int Window::window_init(int x, int y, const char* title) {

    if (!glfwInit())
        return (1);
    window = glfwCreateWindow(x, y, title, nullptr, nullptr);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return (0);
}

void Window::add_object (struct Object* new_obj) {

    object_list.push_back(new_obj);
    std::cerr << "Added ";

    switch (new_obj->object_type) {

        case (POINT):

        case(LINE):

        case(TRI_MESH):

        case(POLY_MESH):

    }

}

/**
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library *
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context *
    window = glfwCreateWindow(1280, 1000, "Hello World", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current *
    glfwMakeContextCurrent(window);


    /* Loop until the user closes the window *
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events *
        glfwPollEvents();

        /* Render here *

        glClear(GL_COLOR_BUFFER_BIT);

        //...

        glBegin(GL_TRIANGLES);

        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.25f);
        glVertex2f(-0.5f, -0.25f);

        glEnd();

        /* Swap front and back buffers *
        glfwSwapBuffers(window);

    }

    glfwTerminate();
    return 0;
}
**/