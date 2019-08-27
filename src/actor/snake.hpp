// Copyright 2019 <Victor Borges>

#ifndef CPP_SNAKE_GAME_ACTOR_SNAKE_HPP
#define CPP_SNAKE_GAME_ACTOR_SNAKE_HPP

#include <vector>
#include <SDL_events.h>
#include "../core/vector2.hpp"
#include "../core/renderer.hpp"
#include "..//core/allocation.hpp"
#include "../core/block.hpp"
#include "../core/controller.hpp"

namespace Capstone
{
class Snake: public GameObject, public fAllocation {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(iVector2 size, iVector2 offset, iVector2 max_offset);
  void update(std::size_t delta_time) override;
  void render(Renderer &renderer) override;
  void prepare(Renderer &renderer) override;

  void grow_body();

  void handle_input(const KeyPressed & key);
  void change_direction(const Direction input, const Direction oposite);

 public:
  Direction direction = Direction::kUp;

  float speed;
  bool alive;
  std::vector<Block> body;

  // Defines the default color of body and head of snake
  Color body_color;
  Color head_color;

  // Defines the color of head when snake is not alive
  Color dead_color;

 private:
  void update_head();
  void update_body(iVector2 &current_head_cell, iVector2 &prev_head_cell);

  iVector2 m_grid;
  bool m_growing;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_ACTOR_SNAKE_HPP
