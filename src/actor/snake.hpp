#ifndef CPP_SNAKE_GAME_ACTOR_SNAKE_HPP
#define CPP_SNAKE_GAME_ACTOR_SNAKE_HPP

#include <vector>
#include <SDL2/SDL_rect.h>
#include "../core/vector2.hpp"

namespace Capstone
{
class Snake
{
 public:
  // Methods
  Snake(int grid_width, int grid_height):
    m_grid{grid_width, grid_height},
    head(grid_width * 0.5f, grid_height * 0.5f)
  {

  }

  void update();

  void grow_body();
  bool snake_cell(iVector2 offset);

 public:
  // Variables
  enum class Direction { kUp, kDown, kLeft, kRight };
  Direction direction = Direction::kUp;

  float speed {0.1f};
  int size {1};
  bool alive {true};
  fVector2 head;
  std::vector<iVector2> body;

 private:
  // Methods
  void update_head ();
  void update_body (iVector2 &current_cell, iVector2 &prev_cell);

 private:
  // Variables
  bool m_growing {false};
  iVector2 m_grid;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_ACTOR_SNAKE_HPP