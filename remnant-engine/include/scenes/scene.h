#ifndef REMNANT_SCENE_H
#define REMNANT_SCENE_H

#include "scene_type.h"

namespace remnant {
    struct SceneInfo { };
    
    struct GeneralSceneInfo {
        SceneType scene_type; // so SceneManager knows which Scene subclass to use
        const SceneInfo* scene_info;
    };

    class Scene {
        public:
            virtual ~Scene() = default;
            virtual void start();
            virtual void update();
    };
}

#endif
