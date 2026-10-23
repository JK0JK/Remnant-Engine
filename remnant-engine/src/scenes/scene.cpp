#include "scene.h"
#include "global.h"
#include "scene_manager.h"

namespace remnant {
    Scene::Scene(const SceneInfo& info) :
    _fadeIn(info.fadeIn),
    _fadeOut(info.fadeOut),
    _screen_effects(),
    _base_screen_effect(info.base_screen_effect)
    {
        BN_LOG(&_screen_effects);
    }

    void Scene::start() {
        if(_fadeIn) { _screen_effects.fade_in(); }
    }

    void Scene::base_update() {
        _screen_effects.update();
        update();
    }

    void Scene::end(int next_scene) {
        if (!_ending) {
            _ending = true;
            //BN_LOG("END SCENE NOW");

            if(_fadeOut) { _screen_effects.fade_out(); }
            game::global_ptr->scene_manager->endSceneAndLoad(next_scene);
        }
    }

    bool Scene::ended() {
        return (_fadeOut == false || _screen_effects.is_black());
    }
}

