#ifndef REMNANT_OBJECT_EVENT_H
#define REMNANT_OBJECT_EVENT_H

#include "bn_fixed.h"

#include "sprite_list.h"
#include "sprite_object.h"

namespace remnant {
    struct ObjectEventInfo {
        const bn::fixed pos_x = 0;
        const bn::fixed pos_y = 0;
        int pos_z = 0;

        int ow_sprite_index = REMNANT_LOGO_64;

        // collision?
    };

    constexpr ObjectEventInfo default_object_event_info = {};

    class ObjectEvent {
        public:
            ObjectEvent(const ObjectEventInfo*);
            virtual void interaction();
        private:
            bn::fixed _pos_x;
            bn::fixed _pos_y;
            int _pos_z;
            SpriteObject _ow_sprite;
    };
}

#endif