#include "scene.h"
#include "global.h"
#include "scene_manager.h"

namespace remnant {
    void Scene::end(int next_scene) {
        BN_LOG("END SCENE NOW");
        game::global_ptr->scene_manager->endSceneAndLoad(next_scene);
    }
}

