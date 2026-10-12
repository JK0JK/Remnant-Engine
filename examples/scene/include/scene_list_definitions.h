// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SCENE_LIST_DEFINITIONS_H
#define EXAMPLE_SCENE_LIST_DEFINITIONS_H

#include "scene.h"
#include "screen_effects_scene.h"
#include "remnant_logo_scene.h"
#include "topdown_scene.h"
#include "scene_list.h"

#include "blank_scene.h"

#include "bn_regular_bg_items_one_room_test.h"

#include "bn_regular_bg_items_pizzeria_fnaf1_alpha_bg1.h"

namespace game {
    constexpr remnant::BlankSceneInfo blank_scene;
    constexpr game::ScreenEffectsSceneInfo screen_effects_test = game::ScreenEffectsSceneInfo{}.with_default_next_scene(REMNANT_LOGO_SCENE).with_background_color(31,31,0);
    constexpr game::RemnantLogoSceneInfo remnant_logo_test = game::RemnantLogoSceneInfo{}.with_default_next_scene(TOPDOWN_SCENE).with_background_color(31,31,0);;
    constexpr remnant::TopDownSceneInfo topdown1 = remnant::TopDownSceneInfo{}.with_default_next_scene(DEFAULT_SCENE).with_bg_base(&bn::regular_bg_items::one_room_test);
    constexpr remnant::TopDownSceneInfo freddys = remnant::TopDownSceneInfo{}.with_default_next_scene(SCREEN_EFFECTS_SCENE).with_bg_base(&bn::regular_bg_items::pizzeria_fnaf1_alpha_bg1);


    constexpr remnant::GeneralSceneInfo scene_list[] = {
        [BLANK_SCENE] = {remnant::BlankScene::create, &blank_scene},
        [SCREEN_EFFECTS_SCENE] = {game::ScreenEffectsScene::create, &screen_effects_test},
        [REMNANT_LOGO_SCENE] = {game::RemnantLogoScene::create, &remnant_logo_test},
        [TOPDOWN_SCENE] = {remnant::TopDownScene::create, &freddys},
    };
}

#endif