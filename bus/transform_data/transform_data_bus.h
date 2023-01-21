//
// Created by Ryan Chan on 2023-01-20.
//

#ifndef IMPORTS
#define IMPORTS
#include "../../imports.h"
#endif /* IMPORTS */

#include "data_targets.h"
#include "target.h"

#ifndef GL_WINDOW_UTIL_TRANSFORM_DATA_BUS_H
#define GL_WINDOW_UTIL_TRANSFORM_DATA_BUS_H


class TransformBus {

private:
    static TransformBus* self;
    std::vector<DataTarget*> targets;
    TransformBus();

public:
    static const TransformBus* instance();
    void register_target(DataTarget* victim);

};


#endif //GL_WINDOW_UTIL_TRANSFORM_DATA_BUS_H
