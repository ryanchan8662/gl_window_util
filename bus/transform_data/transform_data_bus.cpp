//
// Created by Ryan Chan on 2023-01-20.
//

#include "transform_data_bus.h"

TransformBus* TransformBus::self = nullptr;

TransformBus::TransformBus() {

    targets = std::vector<DataTarget*>();

}

const TransformBus* TransformBus::instance() {

    if (self == nullptr)
        self = new TransformBus();

    return (self);

}

void TransformBus::register_target(DataTarget* victim) {



}