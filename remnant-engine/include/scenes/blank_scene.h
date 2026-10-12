#ifndef REMNANT_BLANK_SCENE_H
#define REMNANT_BLANK_SCENE_H

#include "scene.h"

namespace remnant {
    struct BlankSceneInfo : SceneInfoBase<BlankSceneInfo> { };

    class BlankScene : public remnant::Scene {
        public:
            BlankScene(BlankSceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void start() override;
            void update() override;
        private:
            int _next_scene;
    };
}

#endif
