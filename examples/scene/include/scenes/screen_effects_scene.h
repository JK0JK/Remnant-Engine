#ifndef EXAMPLE_SCREEN_EFFECTS_SCENE_H
#define EXAMPLE_SCREEN_EFFECTS_SCENE_H

#include "scene.h"
#include "screen_effects.h"

namespace game {
    struct ScreenEffectsSceneInfo : remnant::SceneInfo { };

    class ScreenEffectsScene : public remnant::Scene {
        public:
            ScreenEffectsScene(ScreenEffectsSceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void start() override;
            void update() override;
            void next_state();
        private:
            remnant::ScreenEffects* _screen_effects;
            int _next_scene;
    };
}

#endif
