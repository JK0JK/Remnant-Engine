#include "screen_effects_scene.h"

#include "keypad.h"
#include "global.h"

#include "scene_manager.h"

namespace game {
    ScreenEffectsScene::ScreenEffectsScene(ScreenEffectsSceneInfo scene_info) {
        this->_screen_effects = global_ptr->screen_effects;
        this->_next_scene = scene_info.default_next_scene;
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
        if(bn::keypad::l_pressed()) {
            end(_next_scene);
        }
    }
}
