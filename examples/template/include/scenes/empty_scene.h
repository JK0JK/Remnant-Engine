#ifndef GAME_EMPTY_SCENE_H
#define GAME_EMPTY_SCENE_H

#include "scene.h"

namespace game {
    struct EmptySceneInfo : remnant::SceneInfo { 
        // next scene(?)
    };

    class EmptyScene : public remnant::Scene {
        public:
            EmptyScene(EmptySceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void start() override;
            void update() override;
    };
}

#endif
