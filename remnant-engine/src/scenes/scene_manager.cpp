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

    void SceneManager::endSceneAndLoad(int next_scene) {
        // play scene end sound, if there is any
            // i.e. steps going away
        _scene_to_load = next_scene;
        _state = SceneManagerState::DESTROYING_SCENE;
        // starts the ending sequence
    }

    void SceneManager::update() {
        switch (_state) {
            case SceneManagerState::NO_SCENE:
                scene_start_sequence(); // becomes SCENE_RUNNING
                break;
            case SceneManagerState::SCENE_RUNNING:
                idle_update();
                break;
            case SceneManager::DESTROYING_SCENE:
                is_ended_yet();
                break;
            default:
                break;
        }
    }

    void SceneManager::idle_update() {
        _current_scene->base_update();
        // whatever else's update
    }

    void SceneManager::is_ended_yet() {
        if(_current_scene->ended()) {
            _current_scene.reset();
            _state = SceneManagerState::NO_SCENE;
            scene_start_sequence();
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

    void SceneManager::load_next_scene() {
        _current_scene = createScene(_scene_to_load);
        _state = SceneManagerState::LOADING_SCENE;
    }

    void SceneManager::scene_ending_sequence() {
        _state = SceneManagerState::NO_SCENE;
    }

    void SceneManager::scene_start_sequence() {
        load_next_scene();
        startCurrentScene();
        _state = SceneManagerState::SCENE_RUNNING;
    }
}