#ifndef REMNANT_SCENE_H
#define REMNANT_SCENE_H

#include "bn_unique_ptr.h"
#include "bn_color.h"

#include "scene_list.h" // so all of Scene's children will have access to the scene list #define's

#include "screen_effects.h"

namespace remnant {

    class SceneManager;

    struct SceneInfo {
        bool fadeIn = true;    // does the scene fade in when loaded?
        bool fadeOut = true;   // does the scene fade out before unloaded?
        int default_next_scene = DEFAULT_SCENE;
        const remnant::CameraState base_screen_effect = remnant::CameraState::BUTANO;
        bn::color background_color = bn::color(0,0,0);
    };

    template <typename Derived>  
    struct SceneInfoBase : SceneInfo {
        //this is so stupid but it's necessary in order to preserve inheritance  
        constexpr Derived& with_fadeIn(bool v) { fadeIn = v; return static_cast<Derived&>(*this); }  
        constexpr Derived& with_fadeOut(bool v) { fadeOut = v; return static_cast<Derived&>(*this); }  
        constexpr Derived& with_default_next_scene(int v) { default_next_scene = v; return static_cast<Derived&>(*this); }
        constexpr Derived& with_base_screen_effect(remnant::CameraState v) { base_screen_effect = v; return static_cast<Derived&>(*this);}
        constexpr Derived& with_background_color(bn::color v) { background_color = v; return static_cast<Derived&>(*this);}
        constexpr Derived& with_background_color(int r, int g, int b) { background_color = bn::color(r,g,b); return static_cast<Derived&>(*this);}  
    };

    class Scene {
        public:
            explicit Scene(const SceneInfo& info);
            virtual ~Scene() = default;
            //static bn::unique_ptr<Scene> create(SceneInfo*);
            //must implement create in order for the program to know how to deal with it
            virtual void start();
            void base_update();
            virtual void update() = 0;
            virtual void end(int);
            bool ended();
        private:
            bool _fadeIn = true;
            bool _fadeOut = true;
            bool _ending = false;
        protected:
            remnant::ScreenEffects _screen_effects;
            remnant::CameraState _base_screen_effect = remnant::CameraState::BUTANO;
    };

    struct GeneralSceneInfo {
        using SceneCreationFunction = bn::unique_ptr<Scene>(*)(const SceneInfo*);
        const SceneCreationFunction creation_function;
        const SceneInfo* scene_info; // each Scene subclass will have its own structure
    };
}

#endif
