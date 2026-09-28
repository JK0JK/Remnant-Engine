#ifndef REMNANT_SPRITE_H
#define REMNANT_SPRITE_H

#include "sprite_part.h"
#include "sprite_list.h"

#include "fixed.h"
#include "array.h"
#include "vector.h"
#include "unique_ptr.h"

namespace remnant {
    struct SpriteObjectInfo {
        const bn::fixed start_x;
        const bn::fixed start_y;
        int num_sprites;

        int bg_priority;
        bool horizontal_flip;
        bool vertical_flip;

        const SpritePartInfo* sprite_parts_def;
    };

    class SpriteObject {
        public:
            SpriteObject(int); // select from the list of sprites and load from rom

            // important data
            bn::fixed x();
            bn::fixed y();
            void set_x(bn::fixed);
            void set_y(bn::fixed);
            void set_position(bn::fixed, bn::fixed);

            void update_position();

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
            bn::fixed _x;
            bn::fixed _y;
            int _num_sprites;

            int _bg_priority;
            bool _horizontal_flip;
            bool _vertical_flip;
            bn::vector<bn::unique_ptr<SpritePart>, 128> _sprite_parts;  
            //SpritePart** _sprite_parts;
    };
}

#endif