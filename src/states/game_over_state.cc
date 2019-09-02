
#include "game_over_state.hpp"

namespace Capstone
{

GameOverState::GameOverState (int score):
  m_score(score)
{

}

void GameOverState::update (std::size_t delta_time)
{
  // This update the font color in focus.
  m_button_chooser.update (delta_time);
}

void GameOverState::render (Renderer& renderer)
{
  renderer.clear (Color(0x1E1E1EFF));

  // This renders the fonts
  m_score_font->render (renderer);
  m_title_font->render (renderer);
  m_button_chooser.render (renderer);

  renderer.display ();
}

void GameOverState::prepare (Renderer& renderer)
{
  // This defines the screen center
  iVector2 centered = {
      renderer.get_screen ().x / 2,
      renderer.get_screen ().y / 2
  };

  // This defines the score's font instance
  m_score_font = m_game->get_font ()->create (FontTheme::kDark, FontSize::kSmall);
  m_score_font->set_text("SCORE: " + std::to_string (m_score));
  m_score_font->prepare (renderer);


  // This defines the title's font instance
  m_title_font = m_game->get_font ()->create (FontTheme::kDark, FontSize::kMedium);
  m_title_font->set_text("GAME OVER");
  m_title_font->prepare (renderer);

  // This defines the "play again"'s font instance
  auto play_again_font = m_game->get_font ()->create (FontTheme::kDark, FontSize::kSmall);
  play_again_font->set_text ("PLAY AGAIN");
  play_again_font->prepare (renderer);

  // This defines the quit's font instance
  auto quit_font = m_game->get_font ()->create (FontTheme::kDark, FontSize::kSmall);
  quit_font->set_text ("QUIT");
  quit_font->prepare (renderer);


  // This align the x coordinate of the title's font on center of screen
  m_score_font->offset = centered;
  m_score_font->offset.x -= (m_score_font->size.x / 2);

  // This align the x coordinate of the title's font on center of screen
  m_title_font->offset = centered;
  m_title_font->offset.x -= m_title_font->size.x / 2;

  // This align the x coordinate of the quit's font on center of screen
  quit_font->offset = centered;
  quit_font->offset.x -= quit_font->size.x / 2;

  // This align the x coordinate of the "play again"'s font on center of screen
  play_again_font->offset = centered;
  play_again_font->offset.x -= play_again_font->size.x / 2;

  // This defines the `y` coordinate of each font
  m_score_font->offset.y = play_again_font->offset.y - m_title_font->size.y - 100;
  m_title_font->offset.y = play_again_font->offset.y - m_title_font->size.y - 15;
  quit_font->offset.y = play_again_font->offset.y + quit_font->size.y + 3;

  // This defines the resume's command button
  m_button_chooser.add_button (std::move(play_again_font), [this]() -> void {
      m_game->pop_state ();
  });

  // This defines the quit's command button
  m_button_chooser.add_button (std::move(quit_font), [this]() -> void {
      m_game->is_running = false;
  });

  // It's important to prepare the buttons after add them all.
  m_button_chooser.prepare (renderer);
}

void GameOverState::handle_input (const KeyPressed& key)
{
  m_button_chooser.handle_input (key);
}

} // namespace Capstone
