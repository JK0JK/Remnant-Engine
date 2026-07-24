#include "topdown_scene.h"

namespace remnant {
    TopDownScene::TopDownScene(TopDownSceneInfo data) : 
        _size_x(data.size_x),
        _size_y(data.size_y),
        _north_map(data.north_map),
        _south_map(data.south_map),
        _east_map(data.east_map),
        _west_map(data.west_map)
    {}

    bn::unique_ptr<Scene> TopDownScene::create(const SceneInfo* scene_info) {
        const TopDownSceneInfo* info = static_cast<const TopDownSceneInfo*>(scene_info);  
        return bn::unique_ptr<Scene>(new TopDownScene(*info));  
    }
    
    void TopDownScene::start() {
        // idk
    }

    void TopDownScene::update() {
        //idk
    }
}