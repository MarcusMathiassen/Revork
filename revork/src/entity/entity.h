#pragma once

class Entity {
private:
  
public:
  virtual ~Entity() = default;
  virtual void update() = 0;
  virtual void draw() = 0;
};