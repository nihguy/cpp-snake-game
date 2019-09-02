
#include "pause_state.hpp"

namespace Capstone
{

void PauseState::update (std::size_t delta_time)
{
  // This update the font color in focus.
  m_button_chooser.update (delta_time);
}

void PauseState::render (Renderer& renderer)
{
  renderer.clear (Color(0x1E1E1EFF));

  // This renders the fonts
  m_title->render (renderer);
  m_button_chooser.render (renderer);

  renderer.display ();
}

void PauseState::prepare (Renderer& renderer)
{
  // This defines the screen center
  iVector2 centered = {
    renderer.get_screen ().x / 2,
    renderer.get_screen ().y / 2
  };

  // This defines the title's font instance
  m_title = m_game->get_font ()->create (FontTheme::kDark, FontSize::kMedium);
  m_title->set_text("PAUSED GAME");
  m_title->prepare (renderer);

  // This defines the resume's font instance
  auto resume_font = m_game->get_font ()->create (FontTheme::kDark, FontSize::kSmall);
  resume_font->set_text ("RESUME");
  resume_font->prepare (renderer);

  // This defines the quit's font instance
  auto quit_font = m_game->get_font ()->create (FontTheme::kDark, FontSize::kSmall);
  quit_font->set_text ("QUIT");
  quit_font->prepare (renderer);


  // This align the x coordinate of the title's font on center of screen
  m_title->offset = centered;
  m_title->offset.x -= m_title->size.x / 2;

  // This align the x coordinate of the quit's font on center of screen
  quit_font->offset = centered;
  quit_font->offset.x -= quit_font->size.x / 2;

  // This align the x coordinate of the resume's font on center of screen
  resume_font->offset = centered;
  resume_font->offset.x -= resume_font->size.x / 2;

  // This defines the `y` coordinate of each font
  resume_font->offset.y -= resume_font->size.y / 2;
  m_title->offset.y = resume_font->offset.y - m_title->size.y - 15;
  quit_font->offset.y = resume_font->offset.y + quit_font->size.y + 3;


  // This defines the resume's command button
  m_button_chooser.add_button (std::move(resume_font), [this]() -> void {
      m_game->pop_state ();
  });

  // This defines the quit's command button
  m_button_chooser.add_button (std::move(quit_font), [this]() -> void {
      m_game->is_running = false;
  });

  // It's important to prepare the buttons after add them all.
  m_button_chooser.prepare (renderer);
}

void PauseState::handle_input (const KeyPressed& key)
{
  m_button_chooser.handle_input (key);
}
} // namespace Capstone
