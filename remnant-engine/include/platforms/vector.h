#ifndef RE_VECTOR_H
#define RE_VECTOR_H

#ifndef PLATFORM_ID
    #include "bn_vector.h"
#elif PLATFORM_ID == 0
    #include "bn_vector.h"
#elif PLATFORM_ID == 1
    #include "linux_vector.h"
#elif PLATFORM_ID == 2
    #include "windows_vector.h"
#elif PLATFORM_ID == 3
    #include "macos_vector.h"
#endif

#endif