#ifndef IO
#define IO
#include <iostream>
#include <cstdio>
#endif

#include "Window/Window.h"

int main() {
    std::cout << "Harness started" << std::endl;
    Window* penis = new Window();
    penis->window_init(1280, 720, "penis");
    exit (EXIT_SUCCESS);
}
