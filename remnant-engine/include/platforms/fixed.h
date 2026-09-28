#ifndef RE_FIXED_H
#define RE_FIXED_H

#ifndef PLATFORM_ID
    #include "bn_fixed.h"
#elif PLATFORM_ID == 0
    #include "bn_fixed.h"
#elif PLATFORM_ID == 1
    #include "linux_fixed.h"
#elif PLATFORM_ID == 2
    #include "windows_fixed.h"
#elif PLATFORM_ID == 3
    #include "macos_fixed.h"
#endif

#endif