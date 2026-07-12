#ifndef RE_BLENDING_FADE_ALPHA_HBE_PTR_H
#define RE_BLENDING_FADE_ALPHA_HBE_PTR_H

#ifndef PLATFORM_ID
    #include "bn_blending_fade_alpha_hbe_ptr.h"
#elif PLATFORM_ID == 0
    #include "bn_blending_fade_alpha_hbe_ptr.h"
#elif PLATFORM_ID == 1
    #include "linux_blending_fade_alpha_hbe_ptr.h"
#elif PLATFORM_ID == 2
    #include "windows_blending_fade_alpha_hbe_ptr.h"
#elif PLATFORM_ID == 3
    #include "macos_blending_fade_alpha_hbe_ptr.h"
#endif

namespace re = bn;

#endif