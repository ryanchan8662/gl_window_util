//
// Created by Ryan Chan on 2023-01-21.
//

#ifndef GL_WINDOW_UTIL_TARGET_H
#define GL_WINDOW_UTIL_TARGET_H

struct Transform;

class DataTarget {
private:
    int target_num{};

public:
    virtual void receive (struct Transform package) = 0;


};

#endif //GL_WINDOW_UTIL_TARGET_H
