
#include <iostream>
#include "main_state.hpp"
#include "../sdl/typography.hpp"
#include "pause_state.hpp"

namespace Capstone
{

// This updates the GameObject behavior
void MainState::update (std::size_t delta_time)
{
  m_snake->update (delta_time);

  if(m_snake->get_status () == SnakeStatus::kEating)
  {
    m_food.replace();
    m_snake->growing ();
  }

  if (m_score_font->get_text () != ("SCORE " + std::to_string (m_snake->body.size ())))
  {
    m_score_font->set_text ("SCORE " + std::to_string (m_snake->body.size ()));
  }

  // The font update should be invoked after color and text changes
  m_score_font->update (delta_time);
}

// This renders the GameObjects
void MainState::render (Renderer& renderer)
{
  renderer.clear (Color(0x1E1E1EFF));

  m_score_font->render (renderer);
  m_food.render (renderer);
  m_snake->render(renderer);

  renderer.display ();
}

// This prepared the game to be rendered
void MainState::prepare (Renderer& renderer)
{
  // This defines the actor
  m_snake = std::make_shared<Snake> ();
  m_snake->prepare (renderer);

  // This defines the font
  m_score_font = m_game->get_font ()->create (FontTheme::kDark, FontSize::kSmall);
  m_score_font->set_text ("SCORE " + std::to_string (m_snake->body.size ()));
  m_score_font->prepare (renderer);
  m_score_font->offset.x = renderer.get_screen ().x / 2 - m_score_font->size.x / 2;
  m_score_font->offset.y = renderer.get_screen ().y / 2 - m_score_font->size.y;

  // This defines the food
  m_food.set_target (m_snake);
  m_food.prepare (renderer);
}

// This creates the input handler of the GameState
void MainState::handle_input (const KeyPressed &key)
{
  // This allows the game to reinitialize when the snake has been collided
  // and the user dispatch `Enter` command
//  if (m_snake->get_status () == SnakeStatus::kColliding)
//  {
    if(key == KeyPressed::kEnter)
    {
      m_game->push_state (std::make_unique<PauseState> ());
    }
//  }

  m_snake->handle_input (key);
}
} // namespace Capstone
