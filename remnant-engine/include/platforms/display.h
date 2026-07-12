#ifndef RE_DISPLAY_H
#define RE_DISPLAY_H

#ifndef PLATFORM_ID
    #include "bn_display.h"
#elif PLATFORM_ID == 0
    #include "bn_display.h"
#elif PLATFORM_ID == 1
    #include "linux_display.h"
#elif PLATFORM_ID == 2
    #include "windows_display.h"
#elif PLATFORM_ID == 3
    #include "macos_display.h"
#endif

#endif