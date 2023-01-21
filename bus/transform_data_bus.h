//
// Created by Ryan Chan on 2023-01-20.
//

#ifndef GL_WINDOW_UTIL_TRANSFORM_DATA_BUS_H
#define GL_WINDOW_UTIL_TRANSFORM_DATA_BUS_H


class TransformBus {

private:
    static TransformBus* self;
    TransformBus() = default;

public:
    static const TransformBus* instance();

};


#endif //GL_WINDOW_UTIL_TRANSFORM_DATA_BUS_H
