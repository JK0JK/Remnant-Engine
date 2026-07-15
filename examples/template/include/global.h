#ifndef EXAMPLE_GLOBAL_H
#define EXAMPLE_GLOBAL_H

#include "engine_global.h"

namespace game {
    struct global_data : remnant::global_data {
        // game-specific global data
    };

    extern global_data* global_ptr;
}

#endif
