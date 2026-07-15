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
            remnant::ScreenEffects getScreenEffects();
        private:
            remnant::ScreenEffects _screen_effects;
            bn::unique_ptr<Scene> _current_scene;
            const remnant::SceneInfo* _current_scene_info;
            //remnant::SceneInfo _next_scene;
    };
}

#endif