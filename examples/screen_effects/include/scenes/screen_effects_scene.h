#ifndef EXAMPLE_SCREEN_EFFECTS_SCENE_H
#define EXAMPLE_SCREEN_EFFECTS_SCENE_H

// TODO: copy the ScreenEffects::next_state() implementation to here

#include "scene.h"
#include "screen_effects.h"

namespace game {
    struct ScreenEffectsSceneInfo : remnant::SceneInfo { 
        // next scene(?)
    };

    class ScreenEffectsScene : public remnant::Scene {
        public:
            ScreenEffectsScene(ScreenEffectsSceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void start() override;
            void update() override;
        private:
            remnant::ScreenEffects* _screen_effects;
    };
}

#endif
