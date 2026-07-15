#ifndef REMNANT_SCREEN_EFFECT_TYPE_H
#define REMNANT_SCREEN_EFFECT_TYPE_H

namespace remnant {
    enum CameraState {
        CLEAR,
        BUTANO,
        CAMERA,
        CAMERABLEND,
        FADEIN,
        FADEINCAMERA,
        FADEOUT,
        FADEOUTCAMERA,
        BLACK   // just so you know when it's finished
    };
}

#endif
