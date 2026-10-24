#ifndef REMNANT_SCENE_MANAGER_H
#define REMNANT_SCENE_MANAGER_H

#include "scene.h"

#include "bn_unique_ptr.h"

namespace remnant {
    class SceneManager {
        public:
            SceneManager();
            SceneManager(int);
            void update();
            void endSceneAndLoad(int);

            void scene_start_sequence();
            void scene_ending_sequence();
        private:
            bn::unique_ptr<Scene> createScene(int);
            void startCurrentScene();
            
            void load_next_scene();

            void idle_update();
            void is_ended_yet();
            
            enum SceneManagerState {
                LOADING_SCENE,
                SCENE_RUNNING,
                DESTROYING_SCENE,
                NO_SCENE
            };

            bn::unique_ptr<Scene> _current_scene;
            const remnant::SceneInfo* _current_scene_info;
            SceneManagerState _state;
            int _scene_to_load;
    };
}

#endif