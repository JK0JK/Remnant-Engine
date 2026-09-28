#include "core.h"
#include "color.h"

#include "scene_manager.h"

#include "global.h"

namespace game {  
    global_data* global_ptr;
}

int main() {
    bn::core::init(bn::color(31,31,0));

    game::global_data global_instance = {NULL, NULL};
    game::global_ptr = &global_instance;

    remnant::SceneManager scene_manager;
    game::global_ptr->scene_manager = &scene_manager;

    while (true) {
        scene_manager.update();
        bn::core::update();
    }
}
