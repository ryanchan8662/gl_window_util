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

    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();

        draw();

    }

    glfwTerminate();
    return (0);
}

void Window::add_object (struct Object* new_obj) {

    object_list.push_back(new_obj);
    std::cerr << "Added ";

    switch (new_obj->object_type()) {

        case (POINT):
            std::cout << "Point added" << std::endl;
            break;

        case(LINE):
            std::cout << "Line added" << std::endl;
            break;

        case(TRI_MESH):
            std::cout << "Triangle mesh added" << std::endl;
            break;

        case(POLY_MESH):
            std::cout << "Poly mesh added" << std::endl;
            break;

        default:
            std::cerr << "You're weird. Why'd you want to render an undefined shape?" << std::endl;
            break;
    }

}

void Window::import_object (const std::string* file_name) {

    std::cout << "Importing object " << file_name->c_str() << std::endl;

}

void Window::draw () {

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex3f(0.0f, 0.5f, 1.0f);
    glVertex3f(0.5f, -0.25f, 0.0f);
    glVertex3f(-0.5f, -0.25f, -1.0f);
    glEnd();

    glfwSwapBuffers(window);

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