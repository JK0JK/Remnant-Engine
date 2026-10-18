#ifndef REMNANT_DISCLAIMER_SCENE_H
#define REMNANT_DISCLAIMER_SCENE_H

#include "scene.h"

namespace remnant {
    struct DisclaimerSceneInfo : SceneInfoBase<DisclaimerSceneInfo> { };

    class DisclaimerScene : public remnant::Scene {
        public:
            DisclaimerScene(DisclaimerSceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void start() override;
            void update() override;
        private:
            int _next_scene;
            int _frames_left = 100;
    };
}

#endif
