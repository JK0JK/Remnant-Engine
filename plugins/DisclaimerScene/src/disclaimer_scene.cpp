#include "disclaimer_scene.h"

namespace remnant {
    DisclaimerScene::DisclaimerScene(DisclaimerSceneInfo scene_info) :
        Scene(scene_info),  // slices BlankSceneInfo -> SceneInfo, calls base ctor  
        _next_scene(scene_info.default_next_scene)  
    {}

    // this one is static so other functions can reach it, check "screen_effects_scene.h"
    bn::unique_ptr<remnant::Scene> DisclaimerScene::create(const remnant::SceneInfo* scene_info) {
        const DisclaimerSceneInfo* info = static_cast<const DisclaimerSceneInfo*>(scene_info);  
        return bn::unique_ptr<remnant::Scene>(new DisclaimerScene(*info)); 
    }

    void DisclaimerScene::start() { 
        // spawn text
    }

    void DisclaimerScene::update() {
        if (_frames_left == 0) {
            end(_next_scene);
        }
        _frames_left--;
    }
}
