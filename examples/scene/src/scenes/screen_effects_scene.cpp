#include "screen_effects_scene.h"

#include "bn_keypad.h"

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
        if (bn::keypad::a_pressed()) { next_state(); }
        if(bn::keypad::l_pressed()) {
            end(_next_scene);
        }
    }

    // cycles through the various effects; good for showcases
    void ScreenEffectsScene::next_state()
    {
        switch(global_ptr->screen_effects->current_state())
        {
            case remnant::CameraState::CLEAR:
                global_ptr->screen_effects->set_center_fade();
                break;
            case remnant::CameraState::BUTANO:
                global_ptr->screen_effects->set_camera_feed();
                break;
            case remnant::CameraState::CAMERA:
                global_ptr->screen_effects->set_camera_blend();
                break;
            case remnant::CameraState::CAMERABLEND:
                global_ptr->screen_effects->fade_out();
                break;
            case remnant::CameraState::FADEOUT:
                global_ptr->screen_effects->set_black();
                break;
            case remnant::CameraState::BLACK:
                global_ptr->screen_effects->fade_in();
                break;
            case remnant::CameraState::FADEIN:
                global_ptr->screen_effects->set_clear();
                break;
            default:
                global_ptr->screen_effects->set_clear();
                break;
        }
        global_ptr->screen_effects->reload_alphas_ref();
    }
}
