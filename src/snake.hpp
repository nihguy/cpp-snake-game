#ifndef CPP_SNAKE_GAME_SNAKE_HPP
#define CPP_SNAKE_GAME_SNAKE_HPP

#include <vector>
#include "SDL.h"

namespace Capstone
{
class Snake
{
 public:
  // Methods
  Snake(int grid_width, int grid_height):
    grid_width(grid_width),
    grid_height(grid_height),
    head_x(grid_width / 2),
    head_y(grid_height / 2) {}

  void update();

  void grow_body();
  bool snake_cell(int x, int y);

 public:
  // Variables
  enum class Direction { kUp, kDown, kLeft, kRight };
  Direction direction = Direction::kUp;

  float speed {0.1f};
  int size {1};
  bool alive {true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  // Methods
  void update_head ();
  void update_body (SDL_Point &current_cell, SDL_Point &prev_cell);

 private:
  // Variables
  bool growing {false};
  int grid_width;
  int grid_height;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_SNAKE_HPP