#include "sprite_object.h"

#include "sprite_list_definitions.h"

namespace remnant {
    SpriteObject::SpriteObject(int index) :
    _x(game::sprite_list[index].start_x),
    _y(game::sprite_list[index].start_y),
    _z(game::sprite_list[index].start_z),
    _num_sprites(game::sprite_list[index].num_sprites),
    _bg_priority(game::sprite_list[index].bg_priority),
    _horizontal_flip(game::sprite_list[index].horizontal_flip),
    _vertical_flip(game::sprite_list[index].vertical_flip)
    {
        for (int z_offset = 0; z_offset < _num_sprites; z_offset++) {
            _sprite_parts.push_back(  
                bn::make_unique<SpritePart>(game::sprite_list[index].sprite_parts_def[z_offset], _x, _y, _z, z_offset));
        }
    }

    bn::fixed SpriteObject::x()
        { return _x; }

    bn::fixed SpriteObject::y()
        { return _y; }

    void SpriteObject::set_x(bn::fixed imposed_x) {
        _x = imposed_x;
        update_position();
    }

    void SpriteObject::set_y(bn::fixed imposed_y) {
        _y = imposed_y;
        update_position();
    }

    void SpriteObject::set_position(bn::fixed imposed_x, bn::fixed imposed_y) {
        _x = imposed_x;
        _y = imposed_y;
        update_position();
    }

    void SpriteObject::update_position() {
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_position(_x, _y);
        }
    }

    int SpriteObject::bg_priority() {
        return _bg_priority;
    }

    void SpriteObject::set_bg_priority(int priority) {
        _bg_priority = priority;
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_bg_priority(priority);
        }
    }

    //i have no idea how i'm going to work z-order into this...
    int SpriteObject::z_order() {
        return _z;
    }

    void SpriteObject::set_z_order(int new_z) {
        _z = new_z;
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_z_order(new_z);
        }
    }
    //void put_above();
    //void put_below();

    bool SpriteObject::horizontal_flip() {
        return _horizontal_flip;
    }

    void SpriteObject::set_horizontal_flip(bool isFlipped) {
        _horizontal_flip = isFlipped;
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_horizontal_flip(isFlipped);
        }
    }

    bool SpriteObject::vertical_flip() {
        return _vertical_flip;
    }

    void SpriteObject::set_vertical_flip(bool isFlipped) {
        _vertical_flip = isFlipped;
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_vertical_flip(isFlipped);
        }
    }

    bool SpriteObject::mosaic_enabled() {
        return _sprite_parts[0]->mosaic_enabled();
    }

    void SpriteObject::set_mosaic_enabled(bool mosaic) {
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_mosaic_enabled(mosaic);
        }
    }

    bool SpriteObject::blending_enabled() {
        return _sprite_parts[0]->blending_enabled();
    }

    void SpriteObject::set_blending_enabled(bool mosaic) {
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_blending_enabled(mosaic);
        }
    }

    bool SpriteObject::window_enabled() {
        return _sprite_parts[0]->window_enabled();
    }

    void SpriteObject::set_window_enabled(bool mosaic) {
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_window_enabled(mosaic);
        }
    }

    bool SpriteObject::visible() {
        return _sprite_parts[0]->visible();
    }

    void SpriteObject::set_visible(bool mosaic) {
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_visible(mosaic);
        }
    }

    bn::optional<bn::camera_ptr> SpriteObject::camera() {
        return _sprite_parts[0]->camera();
    }

    void SpriteObject::set_camera(bn::camera_ptr camera) {
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->set_camera(camera);
        }
    }

    void SpriteObject::remove_camera() {
        for (int i = 0; i < _num_sprites; i++) {
            _sprite_parts[i]->remove_camera();
        }
    }

}