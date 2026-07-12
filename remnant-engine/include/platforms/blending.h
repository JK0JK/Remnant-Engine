#ifndef RE_BLENDING_H
#define RE_BLENDING_H

#ifndef PLATFORM_ID
    #include "bn_blending.h"
#elif PLATFORM_ID == 0
    #include "bn_blending.h"
#elif PLATFORM_ID == 1
    #include "linux_blending.h"
#elif PLATFORM_ID == 2
    #include "windows_blending.h"
#elif PLATFORM_ID == 3
    #include "macos_blending.h"
#endif

namespace re = bn;

#endif