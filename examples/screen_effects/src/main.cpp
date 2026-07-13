#include "core.h"
#include "color.h"

#include "screen_effects.h"

int main() {
    bn::core::init(bn::color(31, 31, 31));

    remnant::ScreenEffects effect = remnant::ScreenEffects();

    while (true) {
        effect.update();
        bn::core::update();
    }
}
