#ifndef CPP_SNAKE_GAME_CORE_GAME_STATE_HPP
#define CPP_SNAKE_GAME_CORE_GAME_STATE_HPP

#include "game.hpp"
#include "game_object.hpp"
#include "controller.hpp"

namespace Capstone
{

// It ensures the classes can be accessed before it be defined properly.
class Game;
class Renderer;
enum class KeyPressed;

/**
 * It's the Abstract State from the State Machine design pattern.
 * The inherited class get the common structure necessary to be
 * accessed by Game class (Context).
 *
 * It maintains a reference to the same instance of Game class and
 * uses it to replace the current state, to push the next state or
 * to go back to the previous one.
 */
class GameState: public GameObject
{
 public:
  /**
   * It allows the inherited class to define its own input handler
   *
   * The inherited class can define its own input handler
   * behavior.
   *
   * @param KeyPressed&  The command dispatched that can be used to handle the GameObjects
   */
  virtual void handle_input(const KeyPressed &key) = 0;

  /**
   * This sets the Game class to be accessed by the inherited class
   *
   * It allows the inherited class to "iterate" over GameState's
   * stack or to close the window assigning false to is_running variable.
   *
   * @param Game game  The reference to the Game class instance
   */
  void set_game_handler(Game& game)
  {
    m_game = &game;
  }

 protected:
  /**
   * This keeps the reference to the Game class on inherited class.
   */
  Game *m_game;
};
} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_GAME_STATE_HPP
