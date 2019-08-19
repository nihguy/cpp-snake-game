#ifndef CPP_SNAKE_GAME_CONTROLLER_HPP
#define CPP_SNAKE_GAME_CONTROLLER_HPP

#include "snake.hpp"

namespace Capstone
{
class Controller
{
 public:
  // Methods
  void handle_input (bool &running, Snake &snake) const;

 private:
  // Methods
  void change_direction (Snake &snake, Snake::Direction input,
                         Snake::Direction opposite) const;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CONTROLLER_HPP