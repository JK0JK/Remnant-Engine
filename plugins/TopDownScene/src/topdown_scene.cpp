#include "topdown_scene.h"

#include "global.h"
#include "screen_effects.h"

#include "bn_keypad.h"
#include "bn_window.h"

namespace remnant {
    TopDownScene::TopDownScene(TopDownSceneInfo data) : 
        //_size_x(data.size_x),
        //_size_y(data.size_y)
        Scene(data),
        _bg_base(data.bg_base->create_bg(0,0)),
        _bg_top(data.bg_top->create_bg(0,0)),
        _bg_effects(data.bg_effects->create_bg(0,0)),
        _camera(bn::camera_ptr::create(0, 0)),
        _npc(data.npc, _camera)
    {
        //_remnant_sprite.set_blending_enabled(true); // will be hidden by fades
        _npc.sprite()->set_blending_enabled(false);
        _npc.sprite()->set_window_enabled(true);   // should work as a mask to see _remnant_sprite and the backdrop color
        //bn::window::outside().set_show_blending(true);
        
        _bg_base.set_blending_enabled(true);
        _bg_base.set_priority(3);
        _bg_base.set_camera(_camera);

        _bg_top.set_blending_enabled(true);
        _bg_top.set_priority(2);
        _bg_base.set_camera(_camera);

        _bg_effects.set_blending_enabled(true);
        _bg_effects.set_priority(1);
        _bg_effects.set_camera(_camera);
    }

    bn::unique_ptr<Scene> TopDownScene::create(const SceneInfo* scene_info) {
        const TopDownSceneInfo* info = static_cast<const TopDownSceneInfo*>(scene_info);  
        return bn::unique_ptr<Scene>(new TopDownScene(*info));  
    }

    void TopDownScene::update() {
        //idk
        move_player();
        if(bn::keypad::start_pressed()) {
            end(DEFAULT_SCENE);
        }
    }

    void TopDownScene::move_player() {
        if (bn::keypad::left_held()) {
            _npc.sprite()->set_x(_camera.x() - 5);
            _camera.set_x(_camera.x()-5);
            //_main_character.move_x(-1);
            //_camera.set_x(_main_character.x());
        }
        if (bn::keypad::right_held()) {
            _npc.sprite()->set_x(_camera.x() + 5);
            _camera.set_x(_camera.x()+5);
            //_main_character.move_x(1);
            //_camera.set_x(_main_character.x());
        }
        if (bn::keypad::up_held()) {
            _npc.sprite()->set_y(_camera.y() - 5);
            _camera.set_y(_camera.y()-5);
            //_main_character.move_y(-1);
            //_camera.set_y(_main_character.y());
        }
        if (bn::keypad::down_held()) {
            _npc.sprite()->set_y(_camera.y() + 5);
            _camera.set_y(_camera.y()+5);
            //_main_character.move_y(1);
            //_camera.set_y(_main_character.y());
        }
    }
    
    /*
    void TopDownScene::updateNpcs() {
        for (NPC& npc : _ow_objects) {  
            npc.update();  
        }
    }
        */
}