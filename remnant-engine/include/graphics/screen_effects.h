#ifndef RE_SCREEN_EFFECTS_H
#define RE_SCREEN_EFFECTS_H

#include "blending_fade_alpha.h"
#include "blending_fade_alpha_hbe_ptr.h"
#include "array.h"
#include "display.h"
#include "blending.h"
#include "core.h"
#include "screen_effects_type.h"

namespace remnant {
    class ScreenEffects {
        public:
            ScreenEffects();
            
            void set_clear();
            void set_black();
            void set_center_fade();  
            void set_camera_feed();
            void set_camera_blend();
        
            bool is_black();
        
            void blend_array_with_fade_alphas(bn::array<bn::blending_fade_alpha, bn::display::height()> friendly); 
        
            void fade_in();
            void fade_in_update();
            void fade_in_camera();
            void fade_in_camera_update();
            
            void fade_out();
            void fade_out_camera();
            void fade_out_update();
            void fade_out_camera_update();
        
            void update();
            void next_state();

            CameraState current_state();
            void reload_alphas_ref();
        
        private:
            bn::array<bn::blending_fade_alpha, bn::display::height()> _fade_alphas;
            bn::blending_fade_alpha_hbe_ptr _fade_hbe;
            int _current_frame = 0;
            int _duration_frames = 30;

            CameraState _camera_state = CameraState::CLEAR;
    };
}

#endif
