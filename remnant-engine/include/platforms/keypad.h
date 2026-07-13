#ifndef RE_KEYPAD_H
#define RE_KEYPAD_H

#ifndef PLATFORM_ID
    #include "bn_keypad.h"
#elif PLATFORM_ID == 0
    #include "bn_keypad.h"
#elif PLATFORM_ID == 1
    #include "linux_keypad.h"
#elif PLATFORM_ID == 2
    #include "windows_keypad.h"
#elif PLATFORM_ID == 3
    #include "macos_keypad.h"
#endif

#endif