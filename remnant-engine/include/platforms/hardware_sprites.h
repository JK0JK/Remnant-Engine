#ifndef RE_HW_SPRITES_H
#define RE_HW_SPRITES_H

#ifndef PLATFORM_ID
    #include "bn_hw_sprites.h"
#elif PLATFORM_ID == 0
    #include "bn_hw_sprites.h"
#elif PLATFORM_ID == 1
    #include "linux_hw_sprites.h"
#elif PLATFORM_ID == 2
    #include "windows_hw_sprites.h"
#elif PLATFORM_ID == 3
    #include "macos_hw_sprites.h"
#endif

#endif