// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SCENE_LIST_DEFINITIONS_H
#define EXAMPLE_SCENE_LIST_DEFINITIONS_H

#include "scene.h"
#include "screen_effects_scene.h"
#include "remnant_logo_scene.h"
#include "topdown_scene.h"
#include "scene_list.h"

namespace game {
    constexpr game::ScreenEffectsSceneInfo screen_effects_test = { {true, true, REMNANT_LOGO_SCENE} };
    constexpr game::RemnantLogoSceneInfo remnant_logo_test = { {true, true, SCREEN_EFFECTS_SCENE} };
    constexpr remnant::TopDownSceneInfo topdown1 = { {true, true, DEFAULT_SCENE}, 1, 2, DEFAULT_SCENE, DEFAULT_SCENE, DEFAULT_SCENE, DEFAULT_SCENE};

    constexpr remnant::GeneralSceneInfo scene_list[] = {
        {game::ScreenEffectsScene::create, &screen_effects_test},
        {game::RemnantLogoScene::create, &remnant_logo_test},
        {remnant::TopDownScene::create, &topdown1},
    };
}

#endif