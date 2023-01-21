#ifndef IO
#define IO
#include <iostream>
#include <cstdio>
#endif

#include "Window/Window.h"

int main() {
    std::cout << "Harness started" << std::endl;
    auto* penis = new Window(780, 640, "test window");
    penis->window_init();
    exit (EXIT_SUCCESS);
}
