#include "scene_manager.h"

#include "scene.h"
#include "topdown_scene.h"

#include "scene_list.h"

namespace remnant {
    SceneManager::SceneManager()
    {
        this->_current_scene = createScene(DEFAULT_SCENE);
    }

    SceneManager::SceneManager(int index)
    {
        this->_current_scene = createScene(index);
    }

    void SceneManager::update() {
        _current_scene->update();
    }

    bn::unique_ptr<Scene> SceneManager::createScene(int index) {
        const GeneralSceneInfo& information = game::scene_list[index];
        switch (information.scene_type) {
            case SceneType::TOPDOWN_SCENE:
                return bn::unique_ptr<Scene>(new TopDownScene(*static_cast<const TopDownSceneInfo*>(information.scene_info)));
                break;
            default:
                return createScene(DEFAULT_SCENE);  // equivalent to deltarune's "dog check"
                break;
        }
    }
}