#include "screen_effects_scene.h"

#include "keypad.h"
#include "global.h"

namespace game {
    ScreenEffectsScene::ScreenEffectsScene(ScreenEffectsSceneInfo) {
        this->_screen_effects = global_ptr->screen_effects;
    }

    // this one is static so other functions can reach it, check "screen_effects_scene.h"
    bn::unique_ptr<remnant::Scene> ScreenEffectsScene::create(const remnant::SceneInfo* scene_info) {
        const ScreenEffectsSceneInfo* info = static_cast<const ScreenEffectsSceneInfo*>(scene_info);  
        return bn::unique_ptr<remnant::Scene>(new ScreenEffectsScene(*info)); 
    }

    void ScreenEffectsScene::start() { }

    void ScreenEffectsScene::update() {
        // detect input
        if (bn::keypad::a_pressed()) { global_ptr->screen_effects->next_state(); }
        //_screen_effects.update();
    }
}
