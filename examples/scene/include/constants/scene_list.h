// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SCENE_LIST_H
#define EXAMPLE_SCENE_LIST_H

#include "scene.h"
#include "topdown_scene.h"

#define DEFAULT_SCENE 0
#define SCENE_AMOUNT 1

namespace game {
    constexpr remnant::TopDownSceneInfo topdown1 = { {}, 1, 2};

    constexpr remnant::GeneralSceneInfo scene_list[] = {
        {remnant::TopDownScene::create, &topdown1},
    };
}

#endif