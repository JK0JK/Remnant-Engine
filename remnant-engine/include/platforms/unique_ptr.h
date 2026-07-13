#ifndef RE_UNIQUE_PTR_H
#define RE_UNIQUE_PTR_H

#ifndef PLATFORM_ID
    #include "bn_unique_ptr.h"
#elif PLATFORM_ID == 0
    #include "bn_unique_ptr.h"
#elif PLATFORM_ID == 1
    #include "linux_unique_ptr.h"
#elif PLATFORM_ID == 2
    #include "windows_unique_ptr.h"
#elif PLATFORM_ID == 3
    #include "macos_unique_ptr.h"
#endif

#endif