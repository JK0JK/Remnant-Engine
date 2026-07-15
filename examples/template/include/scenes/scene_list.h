// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SCENE_LIST_H
#define EXAMPLE_SCENE_LIST_H

#include "scene.h"
#include "empty_scene.h"

#define DEFAULT_SCENE 0
#define EMPTY_SCENE 0
#define SCENE_AMOUNT 1

namespace game {
    constexpr game::EmptySceneInfo empty_scene = { {true, true} };

    constexpr remnant::GeneralSceneInfo scene_list[] = {
        {game::EmptyScene::create, &empty_scene}
    };
}

#endif