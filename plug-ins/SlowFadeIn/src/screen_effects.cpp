#include "screen_effects.h"

namespace remnant
{

    // slowed the fades from 30 frames to 60 frames
    void ScreenEffects::fade_in()
    {
        set_black();
        _current_frame = 60;
        _duration_frames = 60;
        _camera_state = CameraState::FADEIN;
    }

    void ScreenEffects::fade_out()
    {
        _current_frame = 0;
        _duration_frames = 60;
        _camera_state = CameraState::FADEOUT;
    }


    // -----------------------------------------------------------------
    //  CODE BELOW THIS IS JUST A COPY FROM THE ORIGINAL SCREEN_EFFECTS
    // -----------------------------------------------------------------


    ScreenEffects::ScreenEffects() :
        _fade_alphas(),
        _fade_hbe(bn::blending_fade_alpha_hbe_ptr::create(_fade_alphas))
    {
        for(auto& a : _fade_alphas)
            a.set_value(0);
    }

    // useful
    // realistically these are the only screen effects that will end up being used
    // prepares the screen for the next frame
    void ScreenEffects::update()
    {
        switch(_camera_state)
        {
            case CameraState::FADEOUT:
                fade_out_update();
                break;
            case CameraState::FADEOUTCAMERA:
                fade_out_camera_update();
                break;
            case CameraState::FADEIN:
                fade_in_update();
                break;
            case CameraState::FADEINCAMERA:
                fade_in_camera_update();
                break;
            default:
                break;
        }
    }

    bool ScreenEffects::is_black() {
        return _camera_state == CameraState::BLACK;
    }

    void ScreenEffects::fade_in_camera() {
        fade_in();
        _camera_state = CameraState::FADEINCAMERA;
    }

    void ScreenEffects::fade_out_camera() {
        fade_out();
        _camera_state = CameraState::FADEOUTCAMERA;
    }

    // the cooler minigame screen effect
    void ScreenEffects::set_camera_blend()
    {
        set_camera_feed();

        int amplitude = bn::display::height() / 2;

        bn::array<bn::blending_fade_alpha, bn::display::height()> friendly;

        for(int i = 0; i < amplitude; ++i)
        {
            bn::fixed alpha = bn::fixed(i) / amplitude;
            friendly[amplitude + i].set_value(alpha);
            friendly[amplitude - i - 1].set_value(alpha);
        }

        blend_array_with_fade_alphas(friendly);

        _camera_state = CameraState::CAMERABLEND;

    }

    // probably useless
    // clears up the screen; probably won't be used
    void ScreenEffects::set_clear()
    {
        for(auto& a : _fade_alphas)
            a.set_value(0);

        _camera_state = CameraState::CLEAR;
    }

    // makes the screen black; probably won't be used
    void ScreenEffects::set_black()
    {
        for(auto& a : _fade_alphas)
            a.set_value(1);

        _camera_state = CameraState::BLACK;
    }

    // butano's default H-Blank effect; really cool but jarring
    void ScreenEffects::set_center_fade()
    {
        int amplitude = bn::display::height() / 2;

        for(int i = 0; i < amplitude; ++i)
        {
            bn::fixed alpha = bn::fixed(i) / amplitude;
            _fade_alphas[amplitude + i].set_value(alpha);
            _fade_alphas[amplitude - i - 1].set_value(alpha);
        }

        _camera_state = CameraState::BUTANO;
    }

    // blends an array of alphas with the one being used; useful for mixing effects
    void ScreenEffects::blend_array_with_fade_alphas(
        bn::array<bn::blending_fade_alpha, bn::display::height()>
        friendly)
    {
        for (int i = 0; i < bn::display::height(); ++i) {
            bn::fixed alpha = (_fade_alphas[i].value() + friendly[i].value()) / 2;
            _fade_alphas[i].set_value(alpha);
        }
    }

    // basic minigame screen effect; doesn't look good on its own
    void ScreenEffects::set_camera_feed()
    {
        for(int i = 0; i < bn::display::height(); i += 2)
        {
            _fade_alphas[i].set_value(bn::fixed(0.3));
            _fade_alphas[i + 1].set_value(0);
        }

        _camera_state = CameraState::CAMERA;
    }

    // fades out the screen without stopping execution
    void ScreenEffects::fade_out_update()
    {
        if(_current_frame <= _duration_frames) {
            bn::fixed alpha = bn::fixed(_current_frame)/_duration_frames;

            for(auto& a : _fade_alphas)
                a.set_value(alpha);

            _fade_hbe.reload_alphas_ref();
            _camera_state = CameraState::FADEOUT;
            _current_frame++;
        } else {
            set_black();
        }
    }

    // fades in the screen without stopping execution
    void ScreenEffects::fade_in_update()
    {
        if(_current_frame >= 0) {
            bn::fixed alpha = bn::fixed(_current_frame)/_duration_frames;

            for(auto& a : _fade_alphas)
                a.set_value(alpha);

            _fade_hbe.reload_alphas_ref();
            _camera_state = CameraState::FADEIN;
            _current_frame--;
        } else {
            set_clear();
        }
    }

    // very scuffed
    // TODO: rework this, pre-calculate  camera+butano blend to avoid lag
    void ScreenEffects::fade_in_camera_update() {
        int amplitude = bn::display::height() / 2;

        bn::array<bn::blending_fade_alpha, bn::display::height()> butano;

        for(int i = 0; i < amplitude; ++i)
        {
            bn::fixed alpha = bn::fixed(i) / amplitude;
            butano[amplitude + i].set_value(alpha);
            butano[amplitude - i - 1].set_value(alpha);
        }

        for(int i = 0; i < bn::display::height(); i += 2)
        {
            bn::fixed alpha = (butano[i].value() + 0.3) / 2;
            butano[i].set_value(alpha);
            butano[i+1].set_value(butano[i+1].value());
        }

        fade_in_update();

        blend_array_with_fade_alphas(butano);
        _fade_hbe.reload_alphas_ref();
        _camera_state = CameraState::FADEINCAMERA;

        if(_current_frame == 0) {
            set_camera_blend();
        }
    }

    // very scuffed
    // TODO: rework this, pre-calculate  camera+butano blend to avoid lag
    // TODO: actually make this work, it doesn't work
    void ScreenEffects::fade_out_camera_update()
    {
        int amplitude = bn::display::height() / 2;

        bn::array<bn::blending_fade_alpha, bn::display::height()> butano;

        for(int i = 0; i < amplitude; ++i)
        {
            bn::fixed alpha = bn::fixed(i) / amplitude;
            butano[amplitude + i].set_value(alpha);
            butano[amplitude - i - 1].set_value(alpha);
        }

        for(int i = 0; i < bn::display::height(); i += 2)
        {
            bn::fixed alpha = (butano[i].value() + 0.3) / 2;
            butano[i].set_value(alpha);
            butano[i+1].set_value(butano[i+1].value());
        }

        fade_out_update();

        blend_array_with_fade_alphas(butano);
        _fade_hbe.reload_alphas_ref();
        _camera_state = CameraState::FADEOUTCAMERA;

        if(_current_frame == _duration_frames) {
            set_camera_blend();
        }
    }

    CameraState ScreenEffects::current_state()
    {
        return _camera_state;
    }

    void ScreenEffects::reload_alphas_ref()
    {
        _fade_hbe.reload_alphas_ref();
    }
}