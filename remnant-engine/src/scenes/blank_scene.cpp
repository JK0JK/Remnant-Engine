#include "blank_scene.h"

#include "bn_keypad.h"

namespace remnant {
    BlankScene::BlankScene(BlankSceneInfo scene_info) :
        Scene(scene_info),  // slices BlankSceneInfo -> SceneInfo, calls base ctor  
        _next_scene(scene_info.default_next_scene) 

        //this->_next_scene = scene_info.default_next_scene;
    {}

    // this one is static so other functions can reach it, check "screen_effects_scene.h"
    bn::unique_ptr<remnant::Scene> BlankScene::create(const remnant::SceneInfo* scene_info) {
        const BlankSceneInfo* info = static_cast<const BlankSceneInfo*>(scene_info);  
        return bn::unique_ptr<remnant::Scene>(new BlankScene(*info)); 
    }

    void BlankScene::start() { }

    void BlankScene::update() {
        end(_next_scene);
    }
}
