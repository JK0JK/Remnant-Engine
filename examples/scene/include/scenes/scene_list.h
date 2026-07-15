// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SCENE_LIST_H
#define EXAMPLE_SCENE_LIST_H

#include "scene.h"
#include "screen_effects_scene.h"
#include "topdown_scene.h"

#define DEFAULT_SCENE 0
#define SCREEN_EFFECTS_SCENE 0
#define TOPDOWN_SCENE 1
#define SCENE_AMOUNT 2

namespace game {
    constexpr game::ScreenEffectsSceneInfo screen_effects_test = { {true, true} };
    constexpr remnant::TopDownSceneInfo topdown1 = { {true, true}, 1, 2};

    constexpr remnant::GeneralSceneInfo scene_list[] = {
        {game::ScreenEffectsScene::create, &screen_effects_test},
        {remnant::TopDownScene::create, &topdown1},
    };
}

#endif