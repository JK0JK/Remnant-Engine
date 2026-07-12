#ifndef RE_BG_PALETTES_H
#define RE_BG_PALETTES_H

#ifndef PLATFORM_ID
    #include "bn_bg_palettes.h"
#elif PLATFORM_ID == 0
    #include "bn_bg_palettes.h"
#elif PLATFORM_ID == 1
    #include "linux_bg_palettes.h"
#elif PLATFORM_ID == 2
    #include "windows_bg_palettes.h"
#elif PLATFORM_ID == 3
    #include "macos_bg_palettes.h"
#endif

namespace re = bn;

#endif