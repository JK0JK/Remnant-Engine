#ifndef REMNANT_SPRITE_PART_H
#define REMNANT_SPRITE_PART_H

#include "sprite_ptr.h"
#include "fixed.h"

namespace remnant {
    struct SpritePartInfo {
        const bn::sprite_item* sprite;
        const bn::fixed offset_x;
        const bn::fixed offset_y;
        bool base_hflipped;
        bool base_vflipped;
    };
    
    class SpritePart {
        public:
            SpritePart(const SpritePartInfo&, bn::fixed, bn::fixed); // select from the list of sprites and load from rom

            bn::fixed offset_x();
            void set_offset_x(bn::fixed);
            bn::fixed offset_y();
            void set_offset_y(bn::fixed);

            // important data
            bn::fixed x();
            bn::fixed y();
            void set_x(bn::fixed);
            void set_y(bn::fixed);
            void set_position(bn::fixed, bn::fixed);

            int bg_priority();
            void set_bg_priority(int);

            //i have no idea how i'm going to work z-order into this...
            /**
            int z_order();
            void set_z_order();
            void put_above();
            void put_below();
            */

            bool horizontal_flip();
            void set_horizontal_flip(bool);
            bool vertical_flip();
            void set_vertical_flip(bool);

            // affine stuff
            /**
            bn::fixed rotation_angle();
            void set_rotation_angle(bn::fixed);

            bn::fixed horizontal_scale();
            void set_horizontal_scale(bn::fixed);
            bn::fixed vertical_scale();
            void set_vertical_scale(bn::fixed);
            void set_scale(bn::fixed, bn::fixed);

            bn::fixed horizontal_shear();
            void set_horizontal_shear(bn::fixed);
            bn::fixed vertical_shear();
            void set_vertical_shear(bn::fixed);
            void set_shear(bn::fixed);
            void set_shear(bn::fixed, bn::fixed);
            */

            // GFX
            bool mosaic_enabled();
            void set_mosaic_enabled(bool);
            bool blending_enabled();
            void set_blending_enabled(bool);
            bool window_enabled();
            void set_window_enabled(bool);
            bool visible();
            void set_visible(bool);
        private:
            bn::fixed _offset_x;
            bn::fixed _offset_y;
            bn::sprite_ptr _sprite;
            bool _base_hflipped;
            bool _base_vflipped;
    };
}

#endif