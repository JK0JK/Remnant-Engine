#ifndef RE_LOG_H
#define RE_LOG_H

#ifndef PLATFORM_ID
    #include "bn_log.h"
#elif PLATFORM_ID == 0
    #include "bn_log.h"
#elif PLATFORM_ID == 1
    #include "linux_log.h"
#elif PLATFORM_ID == 2
    #include "windows_log.h"
#elif PLATFORM_ID == 3
    #include "macos_log.h"
#endif

#endif