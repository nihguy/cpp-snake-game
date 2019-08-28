// Copyright 2019 <Victor Borges>

#ifndef CPP_SNAKE_GAME_CORE_GAME_HPP
#define CPP_SNAKE_GAME_CORE_GAME_HPP

#include <cstdio>
#include <stack>
#include <memory>

#include "game_state.hpp"
#include "game_loop.hpp"
#include "vector2.hpp"
#include "renderer.hpp"

namespace Capstone
{

class GameState;
class GameLoop;
class Renderer;

/**
 * This creates the breadcrumbs from the first screen until the current one.
 *
 * It's the Context of the State Machine design pattern. Running just one screen
 * at a time, it holds a stack with all the screens (GameStates) displayed on the
 * game.
 *
 * It keeps the exactly state of the last screen intact when a new one get focus,
 * making possible go back to them, or add a new one, easily.
 */
class Game {
 public:
  // Prevent improper use of class
  Game(const Game&) = default;
  Game &operator= (const Game&) = delete;

  // Defines usable constructor
  Game(std::unique_ptr<Renderer> renderer);
  virtual ~Game();

  /**
   * This renders the GameState in focus
   *
   * It Renders the GameState in focus using a external rule define as GameLoop
   * and a external Controller that handler the input given to the GameState classes.
   *
   * @param GameLopp   It defines the game loop used on the game.
   * @param Controller   It defines the input handler used on the game.
   * @returns boolean   True if the game is running
   */
  bool render(GameLoop &game_loop, Controller &controller);


  /**
   * This pushes the GameState to the stack
   *
   * Pushing the state, it creates the breadcrumbs from the first state injected until
   * current one.
   *
   * @param std::unique_ptr<GameState> state  It defines the current state
   */
  void push_state(std::unique_ptr<GameState> state);

  /**
   * It deletes the GameState in focus
   *
   * When it removes the GameState in focus, the previous state starts immediately
   * from their last execution, keeping all the data changed until the moment of the
   * last "push_state". In other words `pop_states` allows "pause" and "resume"
   * "behavior-like".
   */
  void pop_state();

  /**
   * This replaces the state in focus by the assigned one as argument
   *
   * Replacing the state, the older will be removed permanently from the stack.
   *
   * @param std::unique_ptr<GameState> state  It defines the state that will replace
   *                                          the current one
   */
  void replace_state(std::unique_ptr<GameState> state);

  /**
   * This returns the GameState in focus
   *
   * @return GameState  The current state in execution
   */
  GameState *peek_state();

 public:

  /**
   * This immediately closes the window if its value is false.
   *
   * The value is the condition used by keep the GameLoop running. It's automatically
   * assigned as false when SDL_QUIT event is dispatched, but can be assigned at any
   * moment by the GameState is focus.
   */
  bool is_running;

 protected:
  /**
   * A stack holding all GameState's used until the current one.
   */
  std::stack<std::unique_ptr<GameState>> m_states;

  /**
   * This holds the Renderer class instance. It ensures that the same instance
   * of the Renderer class can be given to the GameStates' stack classes.
   */
  std::unique_ptr<Renderer> m_renderer;
};
} // namespace Capstone

#endif //CPP_SNAKE_GAME_CORE_GAME_HPP
