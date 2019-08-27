#ifndef CPP_SNAKE_GAME_CORE_GAME_OBJECT_HPP
#define CPP_SNAKE_GAME_CORE_GAME_OBJECT_HPP

#include "renderer.hpp"

namespace Capstone
{

/**
 * This defines the inherited class as a game object.
 *
 * The inherited class will get the pattern to encapsulate their behaviors.
 */
class GameObject
{
 public:
  /**
   * This updates the GameObject's logic.
   *
   * It's invoked at every game loop cycle, respecting the interval time
   * assigned as arguments by the Game class.
   *
   * This method holds the responsibility to update the movement, color,
   * or any other variable necessary to create the GameObject behavior.
   *
   * @param delta_time  The elapsed time since the last game loop.
   */
  virtual void update(std::size_t delta_time) = 0;

  /**
   * This Renders GameObject properly.
   *
   * It's invoked at every game loop cycle to show the game object on
   * the screen.
   *
   * @param renderer  The Renderer instance used to clear the last
   *                  frame and show the object on the screen.
   */
  virtual void render(Renderer &renderer) = 0;

  /**
   * This prepares the GameObject to be rendered.
   *
   * As GameState doesn't hold the Renderer's reference, the following method
   * helps the inherited class to get access to that, before their first
   * execution.
   *
   * This method is invoked just once, when the state get focus for the first
   * time.
   *
   * @param renderer  The Renderer instance to configure the GameObject.
   */
  virtual void prepare(Renderer &renderer) = 0;
};

} // namespace Capstone

#endif //CPP_SNAKE_GAME_CORE_GAME_OBJECT_HPP
