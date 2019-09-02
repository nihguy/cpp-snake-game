
#ifndef CPP_SNAKE_GAME_STATES_SPLASH_SCREEN_STATE_HPP
#define CPP_SNAKE_GAME_STATES_SPLASH_SCREEN_STATE_HPP

#include "../core/game_state.hpp"

namespace Capstone
{

/**
 * This is a simple GameState to display some information about the aim
 * of this project.
 */
class SplashScreenState: public GameState
{
 public:
  /**
   * This displays the Capstone information along the milliseconds defined
   * as argument and jump to the next GameState when the this time is over.   *
   *
   * @param timeout  This define the millisecond used until change the focus
   *                 to the next GameState
   */
  explicit SplashScreenState(std::size_t timeout = 4000);
  /**
   * Destructor
   */
  virtual ~SplashScreenState () = default;

  /**
   * This updates the GameObject's logic.
   *
   * It's invoked at every game loop cycle, respecting the interval time
   * assigned as arguments by the Game class.
   *
   * It checks if the timeout is over and change the font's color, creating
   * a simple fade out effect to them.
   *
   * @param delta_time  The elapsed time since the last game loop.
   */
  void update (std::size_t delta_time) override;

  /**
   * This Renders the GameObjects
   *
   * It's invoked at every game loop cycle to show the game object on
   * the screen. The fonts are rendered properly, on this method.
   *
   * @param renderer  The Renderer instance used to clear the last
   *                  frame and show the object on the screen.
   */
  void render (Renderer& renderer) override;


  /**
   * This prepares the GameObject to be rendered.
   *
   * As the GameState shouldn't hold the Renderer's reference, the following
   * method helps the current class to get access to that. The fonts are
   * aligned on the screen using this method.
   *
   * @param renderer  The Renderer instance to configure the GameObject.
   */
  void prepare (Renderer& renderer) override;


  /**
   * It allows the current class to define its own input handler
   *
   * Basically, if the user press any allowed key the current class will
   * skip the timeout defined and change the focus to the next GameState,
   * immediately.
   *
   * @param key  The command dispatched that can be used to handle the GameObjects
   */
  void handle_input (const KeyPressed& key) override;

 protected:
  /**
   * This variables defines the current GameState's lifetime.
   * When the m_elapsed_time is greater than m_timeout, the current GameState
   * stop to show the font's text and change the focus to the next GameState.
   */
  std::size_t m_timeout;
  std::size_t m_elapsed_time;

  /**
   * This defines the fonts used by the current state
   */
  std::unique_ptr<Font> m_udacity_font;
  std::unique_ptr<Font> m_course_name_font;
  std::unique_ptr<Font> m_capstone_font;
};

} // namespace Capstone


#endif // CPP_SNAKE_GAME_STATES_SPLASH_SCREEN_STATE_HPP
