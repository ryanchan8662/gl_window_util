//
// Created by Ryan Chan on 2023-01-20.
//

#include "transform_data_bus.h"

TransformBus* TransformBus::self = nullptr;

const TransformBus* TransformBus::instance() {

    if (self == nullptr)
        self = new TransformBus();

    return (self);

}