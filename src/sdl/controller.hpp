
#ifndef CPP_SNAKE_GAME_SDL_CONTROLLER_HPP
#define CPP_SNAKE_GAME_SDL_CONTROLLER_HPP

#include "../core/controller.hpp"

namespace SDL
{

/**
 * It's a simple input handler using some fixed keys to dispatch commands
 * like right, left up, down and start. It can be used to manipulate the
 * GameObject respecting the GameState rules.
 */
class Controller: public Capstone::Controller {
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
  Capstone::KeyPressed handle_input (bool& running) override;
};
}
#endif // CPP_SNAKE_GAME_SDL_CONTROLLER_HPP
