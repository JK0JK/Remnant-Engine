#ifndef REMNANT_TOPDOWN_SCENE_H
#define REMNANT_TOPDOWN_SCENE_H

#include "scene.h"

#include "object_event.h"

#include "bn_camera_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_items_empty_bg.h"

namespace remnant {
    struct TopDownSceneInfo : SceneInfoBase<TopDownSceneInfo> { 
        // UI elements how/when
        const bn::regular_bg_item* bg_base = &bn::regular_bg_items::empty_bg;
        const bn::regular_bg_item* bg_top = &bn::regular_bg_items::empty_bg;
        const bn::regular_bg_item* bg_effects = &bn::regular_bg_items::empty_bg;
        // collision layer
        // list of NPCs
        const ObjectEventInfo* npc = &default_object_event_info;
        // list of object events

        constexpr TopDownSceneInfo& with_bg_base(const bn::regular_bg_item* v) { bg_base = v; return *this; }
        constexpr TopDownSceneInfo& with_bg_top(const bn::regular_bg_item* v) { bg_top = v; return *this; }
        constexpr TopDownSceneInfo& with_bg_effects(const bn::regular_bg_item* v) { bg_effects = v; return *this; }
        constexpr TopDownSceneInfo& with_obj_evnt_info(const ObjectEventInfo* v) { npc = v; return *this; }
    };

    class TopDownScene : public Scene {
        public:
            TopDownScene(TopDownSceneInfo);
            static bn::unique_ptr<Scene> create(const SceneInfo*);
            void start() override;
            void update() override;

            void move_player();
        private:
            int _size_x;
            int _size_y;
            bn::regular_bg_ptr _bg_base;
            bn::regular_bg_ptr _bg_top;
            bn::regular_bg_ptr _bg_effects;

            bn::camera_ptr _camera;

            // collision layer
            // list of NPCs / object events
            ObjectEvent _npc;

    };
}

#endif