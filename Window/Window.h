//
// Created by Ryan on 2023-01-16.
//

#ifndef GLFW
#define GLFW

#include <GLFW/glfw3.h>

#endif /* GLFW */

#ifndef STRING
#define STRING

#include <string>

#endif /* STRING */

#ifndef VECTOR
#define VECTOR

#include <vector>

#endif /* VECTOR */

#ifndef IO
#define IO
#include <iostream>
#include <cstdio>
#endif

#ifndef OBJECT
#define OBJECT

#include "Object/Object.h"

#endif /* OBJECT */

#ifndef GL_WINDOW_UTIL_WINDOW_H
#define GL_WINDOW_UTIL_WINDOW_H


class Window {

private:
    GLFWwindow* window;
    std::vector<Object*> object_list;

public:
    Window();
    Window(const Window &in);
    ~Window();

    int window_init (int x, int y, const char* title);
    void add_object (Object* new_obj);
    void import_object (const std::string* file_name);
    void draw ();

};


#endif //GL_WINDOW_UTIL_WINDOW_H
