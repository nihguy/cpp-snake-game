
#include "splash_screen_state.hpp"
#include "main_state.hpp"

namespace Capstone
{

SplashScreenState::SplashScreenState (size_t timeout):
  m_timeout(timeout),
  m_elapsed_time(0)
{

}


void SplashScreenState::update (std::size_t delta_time)
{
  m_elapsed_time += delta_time;

  if (m_timeout <= m_elapsed_time)
  {
    m_game->push_state (std::make_unique<MainState> ());
  }

  // It creates the fade out effect.
  if (m_elapsed_time >= (m_timeout - 600))
  {
    Color color = Color(10, 10, 10, 0);

    m_udacity_font->color += color;
    m_capstone_font->color += color;
    m_course_name_font->color += color;
  }

  // It's important to change the font color before its update
  m_udacity_font->update (delta_time);
  m_capstone_font->update (delta_time);
  m_course_name_font->update (delta_time);
}

void SplashScreenState::render (Renderer& renderer)
{
  renderer.clear (Color::White);

  m_udacity_font->render (renderer);
  m_capstone_font->render (renderer);
  m_course_name_font->render (renderer);

  renderer.display ();
}

void SplashScreenState::prepare (Renderer& renderer)
{
  // This defines the screen center
  iVector2 centered = {
      renderer.get_screen ().x / 2,
      renderer.get_screen ().y / 2,
  };

  // It get the smart pointer of each font using the third party library.
  m_udacity_font = std::move(m_game->get_font ()->create (FontTheme::kLight, FontSize::kSmall));
  m_capstone_font = std::move(m_game->get_font ()->create (FontTheme::kLight, FontSize::kLarge));
  m_course_name_font = std::move(m_game->get_font ()->create (FontTheme::kLight, FontSize::kSmall));

  // Assigning the text before prepare the font to get the correct Allocation
  // of the font's texture. IT'S NECESSARY TO GET THE MEASURES
  m_udacity_font->set_text ("Udacity's");
  m_capstone_font->set_text ("Capstone");
  m_course_name_font->set_text ("C++ Nanodegree");

  m_udacity_font->prepare (renderer);
  m_capstone_font->prepare (renderer);
  m_course_name_font->prepare (renderer);

  // This defines the "capstone"'s font text alignment
  m_capstone_font->offset = centered;
  m_capstone_font->offset.x -= m_capstone_font->size.x / 2;
  m_capstone_font->offset.y -= m_capstone_font->size.y / 2 + 10;

  // This defines "udacity"'s font text alignment
  m_udacity_font->offset = centered;
  m_udacity_font->offset.x -= m_udacity_font->size.x / 2;
  m_udacity_font->offset.y = m_capstone_font->offset.y - 45;

  // This defines the "course name"'s font text alignment
  m_course_name_font->offset = centered;
  m_course_name_font->offset.x -= m_course_name_font->size.x / 2;
  m_course_name_font->offset.y = m_capstone_font->offset.y + m_capstone_font->size.y + 15;
}

void SplashScreenState::handle_input (const KeyPressed& key)
{
  // If any known key is pressed immediately change the focus to the next state
  if (key != KeyPressed::kUndefined)
  {
    m_game->push_state (std::make_unique<MainState> ());
  }
}
} // namespace Capstone