#include "core.h"

int main() {
    re::core::init();

    while (true) {
        re::core::update();
    }
}
