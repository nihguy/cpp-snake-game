
#ifndef CPP_SNAKE_GAME_CORE_GAME_LOOP_HPP
#define CPP_SNAKE_GAME_CORE_GAME_LOOP_HPP

#include "game.hpp"
#include "renderer.hpp"
#include "controller.hpp"

namespace Capstone
{

class Game;
class Controller;

/**
 * This defines the interface to the main loop on game
 *
 * The idea behind this class is to decouple the logic of the game loop
 * from the main structure. This way, we can define a common interface
 * to be accessed by any graphical library such as SDL, SFML or even a
 * terminal control library like ncurses.
 */
class GameLoop
{
 public:

  /**
   * Destructor
   */
  virtual ~GameLoop () = default;

  /**
   * Execute the main loop of the game
   *
   * It allows the Game class to use the GameLoop defined in SDL, or any
   * other library, using the Renderer and Controller specific for their
   * structure.
   *
   * Decoupling the Renderer and the Controller, we can create two controllers,
   * for example: The first using some fixed input identifiers, and last one
   * using the input defined by the user, effortlessly.
   *
   * @param game  The Game instance used to handle the GameState
   * @param renderer  Define the common interface used to render the object.
   * @param controller  This defines the input handler used by the game
   * @return boolean  If false it closes the game window
   */
  virtual bool execute(Game &game, Renderer &renderer, Controller &controller) const = 0;
};
} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_GAME_LOOP_HPP
