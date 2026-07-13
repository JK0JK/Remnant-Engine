#ifndef REMNANT_SCENE_MANAGER_H
#define REMNANT_SCENE_MANAGER_H

#include "scene.h"
#include "unique_ptr.h"

namespace remnant {
    class SceneManager {
        public:
            SceneManager();
            SceneManager(int);
            void update();
            bn::unique_ptr<Scene> createScene(int);
        private:
            bn::unique_ptr<Scene> _current_scene;
            //remnant::SceneInfo _next_scene;
    };
}

#endif