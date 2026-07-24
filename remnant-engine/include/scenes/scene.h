#ifndef REMNANT_SCENE_H
#define REMNANT_SCENE_H

#include "unique_ptr.h"
#include "scene_list.h"

namespace remnant {

    class SceneManager;

    struct SceneInfo {
        bool fadeIn;    // does the scene fade in when loaded?
        bool fadeOut;   // does the scene fade out before unloaded?
        int default_next_scene;
    };

    class Scene {
        public:
            virtual ~Scene() = default;
            //static bn::unique_ptr<Scene> create(SceneInfo*);
            //must implement create in order for the program to know how to deal with it
            virtual void start();
            virtual void update();
            virtual void end(int);
    };

    struct GeneralSceneInfo {
        using SceneCreationFunction = bn::unique_ptr<Scene>(*)(const SceneInfo*);
        const SceneCreationFunction creation_function;
        const SceneInfo* scene_info; // each Scene subclass will have its own structure
    };
}

#endif
