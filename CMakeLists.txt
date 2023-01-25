cmake_minimum_required(VERSION 3.23)
project(gl_window_util)

include_directories(/opt/homebrew/Cellar)

find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} harness.cpp window/Window.cpp window/Window.h

        window/Event_handler.cpp window/Event_handler.h

        bus/transform_data/transform_data_bus.cpp bus/transform_data/transform_data_bus.h bus/transform_data/data_targets.h bus/transform_data/target.h render/renderer.h)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} glm)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()