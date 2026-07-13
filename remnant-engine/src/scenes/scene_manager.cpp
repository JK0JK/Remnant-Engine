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
        const GeneralSceneInfo& scene_maker = game::scene_list[index];
        return scene_maker.creation_function(scene_maker.scene_info);
    }
}