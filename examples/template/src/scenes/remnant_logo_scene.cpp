#include "remnant_logo_scene.h"

#include "keypad.h"
#include "global.h"
#include "bn_sprite_items_proto_remnant_logo.h"

namespace game {
    RemnantLogoScene::RemnantLogoScene(RemnantLogoSceneInfo scene_info) :
        _remnant_sprite(bn::sprite_items::proto_remnant_logo.create_sprite(0,0)),
        _next_scene(scene_info.default_next_scene)
    {
        _remnant_sprite.set_blending_enabled(true);
    }

    // this one is static so other functions can reach it, check "screen_effects_scene.h"
    bn::unique_ptr<remnant::Scene> RemnantLogoScene::create(const remnant::SceneInfo* scene_info) {
        const RemnantLogoSceneInfo* info = static_cast<const RemnantLogoSceneInfo*>(scene_info);  
        return bn::unique_ptr<remnant::Scene>(new RemnantLogoScene(*info)); 
    }

    void RemnantLogoScene::start() { }

    void RemnantLogoScene::update() {
        if(bn::keypad::l_pressed()) {
            end(_next_scene);
        }
    }
}
