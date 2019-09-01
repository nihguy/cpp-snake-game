
#ifndef CPP_SNAKE_GAME_STATE_PLAY_STATE_HPP
#define CPP_SNAKE_GAME_STATE_PLAY_STATE_HPP

#include <memory>

#include "../core/game_state.hpp"
#include "../actor/snake.hpp"
#include "../core/food.hpp"
#include "../core/font.hpp"

namespace Capstone
{

/**
 * This defines the main state on game
 *
 * It's the game properly
 */
class MainState: public GameState
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
  void update (std::size_t delta_time) override;

  /**
   * This Renders the GameObjects
   *
   * It's invoked at every game loop cycle to show the game object on
   * the screen. The actor, font and food are renderer inside this method.
   *
   * @param renderer  The Renderer instance used to clear the last
   *                  frame and show the object on the screen.
   */
  void render (Renderer& renderer) override;

  /**
   * This prepares the GameObject to be rendered.
   *
   * As the GameState shouldn't hold the Renderer's reference, the following
   * method helps the current class to get access to that. The actors, food
   * and fonts can be prepared to be render properly.
   *
   * This method is invoked just once, when the state get focus for the first
   * time.
   *
   * @param renderer  The Renderer instance to configure the GameObject.
   */
  void prepare (Renderer& renderer) override;

  /**
   * It allows the current class to define its own input handler
   *
   * It ensures the Snake can use the user input to choose the correct direction
   *
   * @param key  The command dispatched that can be used to handle the GameObjects
   */
  void handle_input (const KeyPressed &key) override;

 protected:
  /**
   * This defines the food GameObject
   */
  Food m_food;

  /**
   * This defines the main actor of the game
   */
  std::shared_ptr<Snake> m_snake;

  /**
   * This defines the font used to display the score on screen
   */
  std::unique_ptr<Font> m_score_font;
};

} // namespace Capstone

#endif //CPP_SNAKE_GAME_STATE_PLAY_STATE_HPP
