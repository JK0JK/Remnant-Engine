#ifndef RE_CORE_H
#define RE_CORE_H

#ifndef PLATFORM_ID
    #include "bn_core.h"
#elif PLATFORM_ID == 0
    #include "bn_core.h"
#elif PLATFORM_ID == 1
    #include "linux_core.h"
#elif PLATFORM_ID == 2
    #include "windows_core.h"
#elif PLATFORM_ID == 3
    #include "macos_core.h"
#endif

#endif