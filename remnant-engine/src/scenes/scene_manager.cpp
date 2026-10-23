#include "scene_manager.h"

#include "bn_bg_palettes.h"
#include "bn_color.h"

#include "scene_list_definitions.h"
#include "global.h"

namespace remnant {
    SceneManager::SceneManager() : SceneManager(BLANK_SCENE) {}

    SceneManager::SceneManager(int index) :
    _state(SceneManagerState::NO_SCENE),
    _scene_to_load(index)
    { }

    void SceneManager::update() {
        switch (_state) {
            case SceneManagerState::NO_SCENE:
                load_next_scene();
                break;
            case SceneManagerState::LOADING_SCENE:
                startCurrentScene();
                break; // should already be loading with update(?)
            case SceneManager::DESTROYING_SCENE:
                is_destroyed_yet();
                break;
                // no break here because it will just do idle_update() anyway
            case SceneManagerState::SCENE_RUNNING:
                idle_update();
                break;
            default:
                break;
        }
    }

    void SceneManager::idle_update() {
        _current_scene->base_update();
    }

    void SceneManager::is_destroyed_yet() {
        if(_current_scene->ended()) {
            _state = SceneManagerState::NO_SCENE;
        } else {
            idle_update();
        }
    }

    bn::unique_ptr<Scene> SceneManager::createScene(int index) {
        const GeneralSceneInfo& scene_maker = game::scene_list[index];
        this->_current_scene_info = scene_maker.scene_info;
        return scene_maker.creation_function(_current_scene_info);
    }

    void SceneManager::startCurrentScene() {
        bn::bg_palettes::set_transparent_color(_current_scene_info->background_color);
        _current_scene->start();
        _state = SceneManagerState::SCENE_RUNNING;
    }

    void SceneManager::endSceneAndLoad(int next_scene) {
        // play scene end sound, if there is any
            // i.e. steps going away
        _scene_to_load = next_scene;
        _state = SceneManagerState::DESTROYING_SCENE;
    }

    void SceneManager::load_next_scene() {
        this->_current_scene = createScene(_scene_to_load);
        _state = SceneManagerState::LOADING_SCENE;
    }
}