#ifndef REMNANT_TOPDOWN_SCENE_H
#define REMNANT_TOPDOWN_SCENE_H

#include "scene.h"

namespace remnant {
    struct TopDownSceneInfo : SceneInfo {
        int size_x;
        int size_y;
        // bg1
        // bg2
        // bg3
        // collision layer
        // list of NPCs
        int north_map;
        int south_map;
        int east_map;
        int west_map;
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
            int _north_map;
            int _south_map;
            int _east_map;
            int _west_map;
    };
}

#endif