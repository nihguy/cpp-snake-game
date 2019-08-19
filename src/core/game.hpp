#ifndef CPP_SNAKE_GAME_CORE_GAME_HPP
#define CPP_SNAKE_GAME_CORE_GAME_HPP

#include <random>
#include "controller.hpp"
#include "renderer.hpp"
#include "../actor/snake.hpp"

namespace Capstone
{
class Game {
 public:
  // Methods
  Game (std::size_t grid_width, std::size_t grid_height);
  void run (Controller const &controller, Renderer &renderer,
            std::size_t target_frame_duration);
  int get_score () const;
  int get_size () const;

 private:
  // Methods
  void place_food ();
  void update ();

 private:
  // Variables
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score {0};
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_GAME_HPP