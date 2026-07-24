#ifndef RE_SPRITE_PTR_H
#define RE_SPRITE_PTR_H

#ifndef PLATFORM_ID
    #include "bn_sprite_ptr.h"
#elif PLATFORM_ID == 0
    #include "bn_sprite_ptr.h"
#elif PLATFORM_ID == 1
    #include "linux_sprite_ptr.h"
#elif PLATFORM_ID == 2
    #include "windows_sprite_ptr.h"
#elif PLATFORM_ID == 3
    #include "macos_sprite_ptr.h"
#endif

#endif