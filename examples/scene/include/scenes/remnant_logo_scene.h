#ifndef EXAMPLE_REMNANT_LOGO_SCENE_H
#define EXAMPLE_REMNANT_LOGO_SCENE_H

#include "scene.h"
#include "sprite_object.h"

namespace game {
    struct RemnantLogoSceneInfo : remnant::SceneInfoBase<RemnantLogoSceneInfo> { 
        // next scene(?)
    };

    class RemnantLogoScene : public remnant::Scene {
        public:
            RemnantLogoScene(RemnantLogoSceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void update() override;
        private:
            remnant::SpriteObject _remnant_sprite;
            int _next_scene;
    };
}

#endif
