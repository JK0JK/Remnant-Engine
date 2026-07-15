// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SCENE_LIST_H
#define EXAMPLE_SCENE_LIST_H

#include "scene.h"
#include "screen_effects_scene.h"
#include "topdown_scene.h"

#define DEFAULT_SCENE 0
#define SCREEN_EFFECTS_SCENE 0
#define SCENE_AMOUNT 1

namespace game {
    constexpr game::ScreenEffectsSceneInfo screen_effects_test = { {true, true} };

    constexpr remnant::GeneralSceneInfo scene_list[] = {
        {game::ScreenEffectsScene::create, &screen_effects_test},
    };
}

#endif