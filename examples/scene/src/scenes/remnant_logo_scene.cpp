#include "remnant_logo_scene.h"

#include "bn_keypad.h"

#include "global.h"
#include "sprite_list_definitions.h"

namespace game {
    RemnantLogoScene::RemnantLogoScene(RemnantLogoSceneInfo scene_info) :
        _remnant_sprite(REMNANT_LOGO_64),
        _next_scene(scene_info.default_next_scene)
    { }

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
