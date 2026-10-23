#ifndef EXAMPLE_SCREEN_EFFECTS_SCENE_H
#define EXAMPLE_SCREEN_EFFECTS_SCENE_H

#include "scene.h"
#include "screen_effects.h"

#include "bn_sprite_ptr.h"

namespace game {
    struct ScreenEffectsSceneInfo : remnant::SceneInfoBase<ScreenEffectsSceneInfo> { };

    class ScreenEffectsScene : public remnant::Scene {
        public:
            ScreenEffectsScene(ScreenEffectsSceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void update() override;
            void next_state();

            void move_player();
        private:
            bn::sprite_ptr _remnant_sprite;
            bn::sprite_ptr _flashlight;
            //remnant::SpriteObject _remnant_sprite;
            //remnant::SpriteObject _flashlight;
            int _next_scene;
    };
}

#endif
