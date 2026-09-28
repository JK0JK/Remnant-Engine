#ifndef EXAMPLE_REMNANT_LOGO_SCENE_H
#define EXAMPLE_REMNANT_LOGO_SCENE_H

#include "scene.h"
#include "sprite_ptr.h"

namespace game {
    struct RemnantLogoSceneInfo : remnant::SceneInfo { 
        // next scene(?)
    };

    class RemnantLogoScene : public remnant::Scene {
        public:
            RemnantLogoScene(RemnantLogoSceneInfo);
            static bn::unique_ptr<remnant::Scene> create(const remnant::SceneInfo*);
            void start() override;
            void update() override;
        private:
            bn::sprite_ptr _remnant_sprite;
            int _next_scene;
    };
}

#endif
