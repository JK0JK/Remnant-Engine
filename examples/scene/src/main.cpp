#include "core.h"
#include "color.h"

#include "scene_manager.h"

int main() {
    bn::core::init(bn::color(0,0,0));

    remnant::SceneManager scene_manager = remnant::SceneManager();

    while (true) {
        scene_manager.update();
        bn::core::update();
    }
}
