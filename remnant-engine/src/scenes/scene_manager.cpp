#include "scene_manager.h"

#include "scene.h"
#include "topdown_scene.h"

#include "scene_list.h"
#include "global.h"

namespace remnant {
    SceneManager::SceneManager() : SceneManager(DEFAULT_SCENE) {}

    SceneManager::SceneManager(int index) :
    _screen_effects()
    {
        game::global_ptr->screen_effects = &_screen_effects;
        this->_current_scene = createScene(index);
        startCurrentScene();
    }

    void SceneManager::update() {
        _screen_effects.update();
        _current_scene->update();
    }

    bn::unique_ptr<Scene> SceneManager::createScene(int index) {
        const GeneralSceneInfo& scene_maker = game::scene_list[index];
        _current_scene_info = scene_maker.scene_info;
        return scene_maker.creation_function(_current_scene_info);
    }

    void SceneManager::startCurrentScene() {
        if(_current_scene_info->fadeIn) { _screen_effects.fade_in(); }
        _current_scene->start();
    }

    remnant::ScreenEffects SceneManager::getScreenEffects() {
        return _screen_effects;
    }
}