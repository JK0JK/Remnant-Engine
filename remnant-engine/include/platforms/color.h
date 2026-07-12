#ifndef RE_COLOR_H
#define RE_COLOR_H

#ifndef PLATFORM_ID
    #include "bn_color.h"
#elif PLATFORM_ID == 0
    #include "bn_color.h"
#elif PLATFORM_ID == 1
    #include "linux_color.h"
#elif PLATFORM_ID == 2
    #include "windows_color.h"
#elif PLATFORM_ID == 3
    #include "macos_color.h"
#endif

namespace re = bn;

#endif