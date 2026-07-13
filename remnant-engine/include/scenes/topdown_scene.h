#ifndef REMNANT_TOPDOWN_SCENE_H
#define REMNANT_TOPDOWN_SCENE_H

#include "scene.h"

namespace remnant {
    struct TopDownSceneInfo : SceneInfo {
        int size_x;
        int size_y;
    };

    class TopDownScene : public Scene {
        public:
            TopDownScene(TopDownSceneInfo);
            static bn::unique_ptr<Scene> create(const SceneInfo*);
            void start() override;
            void update() override;
        private:
            int _size_x;
            int _size_y;
    };
}

#endif