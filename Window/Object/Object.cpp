//
// Created by Ryan Chan on 2023-01-16.
//

#include "Object.h"

std::string Object::object_name () {
    return (name);
}

const glm::mat4x4* Object::object_transforms () {
    return (&transforms);
}

const glm::vec3* Object::object_colour () {
    return (&colour);
}

int Object::object_type () {
    return (type);
}
