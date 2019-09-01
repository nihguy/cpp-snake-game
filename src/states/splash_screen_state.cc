
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

  if (m_elapsed_time >= (m_timeout - 600))
  {
    Color color = Color(10, 10, 10, 0);

    m_udacity_font->color += color;
    m_capstone_font->color += color;
    m_course_name_font->color += color;
  }

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
  m_udacity_font = std::move(m_game->get_font ()->create (FontTheme::kLight, FontSize::kSmall));
  m_capstone_font = std::move(m_game->get_font ()->create (FontTheme::kLight, FontSize::kMedium));
  m_course_name_font = std::move(m_game->get_font ()->create (FontTheme::kLight, FontSize::kExtraSmall));

  m_udacity_font->set_text ("Udacity's");
  m_capstone_font->set_text ("Capstone");
  m_course_name_font->set_text ("C++ NANODEGREE");

  m_udacity_font->prepare (renderer);
  m_capstone_font->prepare (renderer);
  m_course_name_font->prepare (renderer);

  iVector2 screen_center = {
    renderer.get_screen ().x / 2,
    renderer.get_screen ().y / 2,
  };

  m_capstone_font->offset.x = screen_center.x - m_capstone_font->size.x / 2;
  m_capstone_font->offset.y = screen_center.y - m_capstone_font->size.y / 2 - 50;

  m_udacity_font->offset.x = screen_center.x - m_udacity_font->size.x / 2;
  m_udacity_font->offset.y = screen_center.y - m_capstone_font->size.y - 60;

  m_course_name_font->offset.x = screen_center.x - m_course_name_font->size.x / 2;
  m_course_name_font->offset.y = screen_center.y + m_capstone_font->size.y - 40;
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