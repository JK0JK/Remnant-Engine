// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SPRITE_LIST_DEFINITIONS_H
#define EXAMPLE_SPRITE_LIST_DEFINITIONS_H

#include "sprite_list.h"

#include "sprite_object.h"
#include "sprite_part.h"

#include "bn_sprite_items_proto_remnant_logo.h"

namespace game {
    constexpr remnant::SpritePartInfo remnant_logo_parts[] = {
        {&bn::sprite_items::proto_remnant_logo, 0, 0, false, false}
    };

    constexpr remnant::SpriteObjectInfo sprite_list[] = {
        [REMNANT_LOGO_64] = {0, 0, 1, 0, false, false, remnant_logo_parts}
    };
}

#endif