#ifndef REMNANT_GLOBAL_H
#define REMNANT_GLOBAL_H

#include "unique_ptr.h"

namespace remnant {
    class SceneManager;
    class ScreenEffects;

    struct global_data {
        SceneManager* scene_manager;
        ScreenEffects* screen_effects;
    };
}

#endif