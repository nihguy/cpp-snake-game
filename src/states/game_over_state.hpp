
#ifndef CPP_SNAKE_GAME_STATES_GAME_OVER_STATE_HPP
#define CPP_SNAKE_GAME_STATES_GAME_OVER_STATE_HPP

#include "../core/game_state.hpp"
#include "../core/button_chooser.hpp"

namespace Capstone
{
class GameOverState: public GameState
{
 public:
  explicit GameOverState(int score);
  virtual ~GameOverState () = default;

  void update (std::size_t delta_time) override;
  void render (Renderer& renderer) override;
  void prepare (Renderer& renderer) override;
  void handle_input (const KeyPressed& key) override;

 protected:
  /**
   * The font used to display the "score" text
   */
  std::unique_ptr<Font> m_score_font;

  /**
   * The font used to display the "Game Over" text
   */
  std::unique_ptr<Font> m_title_font;

  /**
   * The button list used to define the options: play again and quit
   */
  ButtonChooser m_button_chooser;

  /**
   * This holds the score of the game
   */
  int m_score;
};
} // namespace Capstone


#endif // CPP_SNAKE_GAME_STATES_GAME_OVER_STATE_HPP
