
#ifndef CPP_SNAKE_GAME_STATES_PAUSE_STATE_HPP
#define CPP_SNAKE_GAME_STATES_PAUSE_STATE_HPP

#include "../core/game_state.hpp"
#include "../core/button_chooser.hpp"

namespace Capstone
{

/**
 * This GameState is used to allow the user to select between
 * resume the game or quit the window.
 */
class PauseState: public GameState
{
 public:
  /**
   * This updates the GameObject's logic.
   *
   * It's invoked at every game loop cycle, respecting the interval time
   * assigned as arguments by the Game class.
   *
   * This method holds the responsibility to update the color of the button.
   *
   * @param delta_time  The elapsed time since the last game loop.
   */
  void update (std::size_t delta_time) override;

  /**
   * This Renders the GameObjects
   *
   * It's invoked at every game loop cycle to show the game object on
   * the screen. The font and buttons are rendered inside this method.
   *
   * @param renderer  The Renderer instance used to clear the last
   *                  frame and show the object on the screen.
   */
  void render (Renderer& renderer) override;


  /**
   * This prepares the GameObject to be rendered.
   *
   * As the GameState shouldn't hold the Renderer's reference, the following
   * method helps the current class to get access to that. The font and buttons
   * are prepared to be rendered properly.
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
   * It ensures the ButtonChooser can use the user input to choose the
   * correct button in focus.
   *
   * @param key  The command dispatched that can be used to handle the GameObjects
   */
  void handle_input (const KeyPressed& key) override;

 protected:

  /**
   * The font used to display the "Pause Game" text
   */
  std::unique_ptr<Font> m_title;

  /**
   * The button list used to define the options: resume and quit
   */
  ButtonChooser m_button_chooser;
};
} // namespace Capstone

#endif // CPP_SNAKE_GAME_STATES_PAUSE_STATE_HPP
