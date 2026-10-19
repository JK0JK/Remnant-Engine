#include "sprite_part.h"

#include "sprite_list_definitions.h"

namespace remnant {

    SpritePart::SpritePart(const SpritePartInfo& info, bn::fixed mother_x, bn::fixed mother_y, int mother_z, int offset_z) :
    _offset_x(info.offset_x), // get from the table
    _offset_y(info.offset_y), // get from the table
    _offset_z(offset_z),    // sprite part order among other SpriteParts in this SpriteObject
    _sprite(info.sprite->create_sprite(mother_x + _offset_x, mother_y + _offset_y)),
    _base_hflipped(info.base_hflipped),   // get from the table
    _base_vflipped(info.base_vflipped)   // get from the table
    {
        // select from the list of sprites and load from rom
        _sprite.set_vertical_flip(_base_vflipped);
        _sprite.set_horizontal_flip(_base_hflipped);
        _sprite.set_blending_enabled(true);
    }

    bn::fixed SpritePart::offset_x() 
        { return _offset_x; }

    void SpritePart::set_offset_x(bn::fixed new_offset)
        { _offset_x = new_offset; }

    bn::fixed SpritePart::offset_y() 
        { return _offset_y; }

    void SpritePart::set_offset_y(bn::fixed new_offset)
        { _offset_y = new_offset; }

    // important data
    bn::fixed SpritePart::x()
        { return _sprite.x(); }

    bn::fixed SpritePart::y()
        { return _sprite.y(); }

    void SpritePart::set_x(bn::fixed imposed_x) 
        { _sprite.set_x(imposed_x + _offset_x); }

    void SpritePart::set_y(bn::fixed imposed_y)
        { _sprite.set_y(imposed_y + _offset_y); }

    void SpritePart::set_position(bn::fixed imposed_x, bn::fixed imposed_y)
        { _sprite.set_position(imposed_x + _offset_x, imposed_y + _offset_y); }

    int SpritePart::bg_priority()
        { return _sprite.bg_priority(); }
    
    void SpritePart::set_bg_priority(int imposed_bg_priority)
        { _sprite.set_bg_priority(imposed_bg_priority); }

    int SpritePart::z_order() { return _sprite.z_order(); }

    void SpritePart::set_z_order(int imposed_z) { _sprite.set_z_order(imposed_z + _offset_z); }

    //void put_above();
    //void put_below();

    bool SpritePart::horizontal_flip()
        { return _sprite.horizontal_flip(); }

    void SpritePart::set_horizontal_flip(bool isFlipped) {
        if(isFlipped ^ horizontal_flip()) { // if flip will change sprite
            _sprite.set_horizontal_flip(isFlipped ^ _base_hflipped);
            _offset_x = _offset_x * -1.0;
            set_x(x());
        }
    }

    bool SpritePart::vertical_flip()
        { return _sprite.vertical_flip(); }

    void SpritePart::set_vertical_flip(bool isFlipped) {
        if(isFlipped ^ vertical_flip()) {   // if flip will change sprite
            _sprite.set_vertical_flip(isFlipped ^ _base_vflipped);
            _offset_y = _offset_y * -1.0;
            set_y(y());
        }
    }

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
    bool SpritePart::mosaic_enabled()
        { return _sprite.mosaic_enabled(); }

    void SpritePart::set_mosaic_enabled(bool isMosaic)
        { _sprite.set_mosaic_enabled(isMosaic); }

    bool SpritePart::blending_enabled()
        { return _sprite.blending_enabled(); }

    void SpritePart::set_blending_enabled(bool isBlended)
        { _sprite.set_blending_enabled(isBlended); }
    
    bool SpritePart::window_enabled()
        { return _sprite.window_enabled(); }
    
    void SpritePart::set_window_enabled(bool isWindow)
        { _sprite.set_window_enabled(isWindow); }
    
    bool SpritePart::visible()
        { return _sprite.visible(); }
    
    void SpritePart::set_visible(bool isVisible)
        { _sprite.set_visible(isVisible); }

    bn::optional<bn::camera_ptr> SpritePart::camera()
        { return _sprite.camera(); }
    
    void SpritePart::set_camera(bn::camera_ptr camera)
        { _sprite.set_camera(camera); }

    void SpritePart::remove_camera()
        { _sprite.remove_camera(); }
    
}