
#ifndef CPP_SNAKE_GAME_STATES_SPLASH_SCREEN_STATE_HPP
#define CPP_SNAKE_GAME_STATES_SPLASH_SCREEN_STATE_HPP

#include "../core/game_state.hpp"

namespace Capstone
{

class SplashScreenState: public GameState
{
 public:

  SplashScreenState(std::size_t timeout = 4000);
  /**
   * Destructor
   */
  virtual ~SplashScreenState () = default;

  void update (std::size_t delta_time) override;
  void render (Renderer& renderer) override;
  void prepare (Renderer& renderer) override;
  void handle_input (const KeyPressed& key) override;

 protected:
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
