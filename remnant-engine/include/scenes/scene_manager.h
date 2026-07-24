#ifndef REMNANT_SCENE_MANAGER_H
#define REMNANT_SCENE_MANAGER_H

#include "scene.h"
#include "unique_ptr.h"
#include "screen_effects.h"

namespace remnant {
    class SceneManager {
        public:
            SceneManager();
            SceneManager(int);
            void update();
            bn::unique_ptr<Scene> createScene(int);
            void startCurrentScene();
            void endSceneAndLoad(int);
            void load_next_scene();
            remnant::ScreenEffects getScreenEffects();

            void idle_update();
            void is_destroyed_yet();
        private:
            remnant::ScreenEffects _screen_effects;
            bn::unique_ptr<Scene> _current_scene;
            const remnant::SceneInfo* _current_scene_info;
            
            enum SceneManagerState {
                LOADING_SCENE,
                SCENE_RUNNING,
                DESTROYING_SCENE,
                NO_SCENE
            };

            SceneManagerState _state;
            int _scene_to_load;
    };
}

#endif