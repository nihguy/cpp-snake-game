
#include <iostream>
#include "main_state.hpp"

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
}

// This renders the GameObjects
void MainState::render (Renderer& renderer)
{
  renderer.clear (Color(0x1E1E1EFF));

  m_food.render (renderer);
  m_snake->render(renderer);

  renderer.display ();
}

// This prepared the game to be rendered
void MainState::prepare (Renderer& renderer)
{
  m_snake = std::make_shared<Snake> ();
  m_snake->prepare (renderer);

  m_food.set_target (m_snake);
  m_food.prepare (renderer);

}

// This creates the input handler of the GameState
void MainState::handle_input (const KeyPressed &key)
{
  // This allows the game to reinitialize when the snake has been collided
  // and the user dispatch `Enter` command
  if (m_snake->get_status () == SnakeStatus::kColliding)
  {
    if(key == KeyPressed::kEnter)
    {
      m_snake->reset();
    }
  }

  m_snake->handle_input (key);
}
} // namespace Capstone
