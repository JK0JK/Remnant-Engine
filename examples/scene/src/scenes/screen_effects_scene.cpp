#include "screen_effects_scene.h"

#include "bn_keypad.h"

#include "global.h"

#include "scene_manager.h"

#include "bn_blending.h"

#include "bn_window.h"
#include "bn_inside_window.h"

#include "bn_sprite_items_proto_remnant_logo.h"

namespace game {
    ScreenEffectsScene::ScreenEffectsScene(ScreenEffectsSceneInfo scene_info) : 
        _screen_effects(global_ptr->screen_effects),
        _remnant_sprite(bn::sprite_items::proto_remnant_logo.create_sprite(32,32)),
        _flashlight(bn::sprite_items::proto_remnant_logo.create_sprite(16,16)),
        _next_scene(scene_info.default_next_scene)
    {
        _flashlight.set_z_order(1000);
        _remnant_sprite.set_blending_enabled(true); // will be hidden by fades
        _flashlight.set_window_enabled(true);   // should work as a mask to see _remnant_sprite and the backdrop color
        bn::window::sprites().set_show_blending(false);

        // this is being stopped by a bug in butano
        // 0x07000009 is becoming 11 (invalid) for some reason; butano is likely attempting to make _remnant both blend and window
        // emu:write16(0x07000009, 0x00) fixes it until any of _remnant's OAM attributes (namely position) changes and gets reset
        // to what butano thinks they should be
        // hopefully will be fixed someday
    }

    // this one is static so other functions can reach it, check "screen_effects_scene.h"
    bn::unique_ptr<remnant::Scene> ScreenEffectsScene::create(const remnant::SceneInfo* scene_info) {
        const ScreenEffectsSceneInfo* info = static_cast<const ScreenEffectsSceneInfo*>(scene_info);  
        return bn::unique_ptr<remnant::Scene>(new ScreenEffectsScene(*info)); 
    }

    void ScreenEffectsScene::start() {}

    void ScreenEffectsScene::update() {
        // detect input
        move_player();

        if (bn::keypad::a_pressed()) { next_state(); }
        if(bn::keypad::l_pressed()) {
            end(_next_scene);
        } if (bn::keypad::b_pressed()) {
        }
        /*bn::inside_window::sprites().set_visible(true);
        bn::window::sprites().set_show_blending(false);*/
    }

    void ScreenEffectsScene::move_player() {
        if (bn::keypad::left_held()) {
            _flashlight.set_x(_flashlight.x()-1);
            //_main_character.move_x(-1);
            //_flashlight.set_x(_main_character.x());
        }
        if (bn::keypad::right_held()) {
            _flashlight.set_x(_flashlight.x()+1);
            //_main_character.move_x(1);
            //_flashlight.set_x(_main_character.x());
        }
        if (bn::keypad::up_held()) {
            _flashlight.set_y(_flashlight.y()-1);
            //_main_character.move_y(-1);
            //_flashlight.set_y(_main_character.y());
        }
        if (bn::keypad::down_held()) {
            _flashlight.set_y(_flashlight.y()+1);
            //_main_character.move_y(1);
            //_flashlight.set_y(_main_character.y());
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
