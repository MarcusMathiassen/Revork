#pragma once

#include "window_manager.h"
#include "renderer/renderer.h"
#include "entity/gameobject.h"

#include <vector>

class Revork {
  
public:
    WindowManager window_manager;
    Renderer      renderer;
    
    bool app_is_running = true;

    void init();
    void shutdown();
    void run();
    void draw_loop();
    void add_gameobject(GameObject *gameobject)
    {
      renderer.entities.emplace_back(gameobject);
    }
};
