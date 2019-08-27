#ifndef CPP_SNAKE_GAME_CORE_CONTROLLER_HPP
#define CPP_SNAKE_GAME_CORE_CONTROLLER_HPP

#include "game.hpp"

namespace Capstone
{

class Game;

/**
 * This defines the keys used to handle the game
 */
enum class KeyPressed
{
  kUndefined,
  kUp,
  kLeft,
  kDown,
  kRight,
  kEnter,
};

/**
 *
 */
class Controller
{
 public:

  /**
   * This handles the input dispatched by the user
   *
   * It defines if the Key pressed by the user is a valid command
   * and return a enum representing this command.
   *
   * @param running  This boolean defines if the close should be closed
   * @return KeyPressed  The command equivalent to key pressed by the user
   */
  virtual KeyPressed handle_input(bool& running) = 0;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_CONTROLLER_HPP