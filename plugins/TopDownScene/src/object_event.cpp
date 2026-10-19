#include "object_event.h"

#include "sprite_list_definitions.h"

namespace remnant {
    ObjectEvent::ObjectEvent(const ObjectEventInfo* info, bn::camera_ptr camera) :
    _pos_x(info->pos_x),
    _pos_y(info->pos_y),
    _pos_z(info->pos_z),
    _ow_sprite(info->ow_sprite_index)
    {
        _ow_sprite.set_camera(camera);
        _ow_sprite.set_x(_pos_x);
        _ow_sprite.set_y(_pos_y);
        _ow_sprite.set_z_order(_pos_z);
    }

    void ObjectEvent::interaction() {
        // to be defined by every child of ObjectEvent
    }
}