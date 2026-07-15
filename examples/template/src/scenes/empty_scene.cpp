#include "empty_scene.h"

namespace game {
    EmptyScene::EmptyScene(EmptySceneInfo) { }

    // this one is static so other functions can reach it, check "screen_effects_scene.h"
    bn::unique_ptr<remnant::Scene> EmptyScene::create(const remnant::SceneInfo* scene_info) {
        const EmptySceneInfo* info = static_cast<const EmptySceneInfo*>(scene_info);  
        return bn::unique_ptr<remnant::Scene>(new EmptyScene(*info)); 
    }

    void EmptyScene::start() {
        // setup after constructor
    }

    void EmptyScene::update() {
        // updates every frame
    }
}
