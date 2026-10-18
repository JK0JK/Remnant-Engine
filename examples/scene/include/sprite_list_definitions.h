// TODO: make this generate automatically (?)

#ifndef EXAMPLE_SPRITE_LIST_DEFINITIONS_H
#define EXAMPLE_SPRITE_LIST_DEFINITIONS_H

#include "sprite_list.h"

#include "sprite_object.h"
#include "sprite_part.h"

#include "bn_sprite_items_empty_sprite.h"
#include "bn_sprite_items_proto_remnant_logo.h"

namespace game {
    constexpr remnant::SpritePartInfo empty_sprite[] = {
        {&bn::sprite_items::empty_sprite, 0, 0, false, false},
    };

    constexpr remnant::SpritePartInfo remnant_logo_parts[] = {
        {&bn::sprite_items::proto_remnant_logo, 32, 32, false, false},
        {&bn::sprite_items::proto_remnant_logo, -32, -32, false, false},
        {&bn::sprite_items::proto_remnant_logo, 32, -32, false, false},
        {&bn::sprite_items::proto_remnant_logo, -32, 32, false, false}
    };

    template<typename T, size_t N>  
    constexpr size_t num_sprites(const T (&sprite_parts)[N]) {  
        return N;  
    };

    constexpr remnant::SpriteObjectInfo sprite_list[] = {
        [NO_SPRITE] = {.num_sprites = 0, .sprite_parts_def = empty_sprite},
        [REMNANT_LOGO_64] = {.num_sprites = num_sprites(remnant_logo_parts), .sprite_parts_def = remnant_logo_parts}
    };

    // TODO: figure out frames for animation
}

#endif