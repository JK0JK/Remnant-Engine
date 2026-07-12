#ifndef RE_ARRAY_H
#define RE_ARRAY_H

#ifndef PLATFORM_ID
    #include "bn_array.h"
#elif PLATFORM_ID == 0
    #include "bn_array.h"
#elif PLATFORM_ID == 1
    #include "linux_array.h"
#elif PLATFORM_ID == 2
    #include "windows_array.h"
#elif PLATFORM_ID == 3
    #include "macos_array.h"
#endif

namespace re = bn;

#endif