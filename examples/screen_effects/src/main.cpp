#include "core.h"
#include "screen_effects.h"

#include "color.h"
#include "bg_palettes.h"

int main() {
    re::core::init();

    re::bg_palettes::set_transparent_color(re::color(31, 31, 31));

    ScreenEffects effect = ScreenEffects();

    while (true) {
        effect.update();
        re::core::update();
    }
}
