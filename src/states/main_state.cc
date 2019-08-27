
#include <iostream>
#include "main_state.hpp"

namespace Capstone
{

void MainState::update (std::size_t delta_time)
{
  m_snake->update (delta_time);

  if (m_snake->get_allocation_as<int> ().check_collision (*m_food))
  {
    m_snake->grow_body ();
    m_food->offset.x = m_random.get_x ();
    m_food->offset.y = m_random.get_y ();
  }
}

void MainState::render (Renderer& renderer)
{
  renderer.clear (Color(0x1E1E1EFF));

  m_food->render (renderer);
  m_snake->render(renderer);

  renderer.display ();
}

void MainState::prepare (Renderer& renderer)
{
  iVector2 size {
    renderer.get_screen ().x / renderer.get_grid ().x,
    renderer.get_screen ().y / renderer.get_grid ().y
  };

  auto grid = renderer.get_grid ();
  m_random.max = { grid.x - 1, grid.y - 1 };

  m_food = std::make_unique<Block> (size, iVector2(m_random.get_x (), m_random.get_y ()));
  m_food->color = Color(0xFFCC00FF);

  m_snake = std::make_unique<Snake> (size, iVector2 { 31, 31 }, grid);
  m_snake->body_color = Color::White;
  m_snake->head_color = Color(0x7ACCFFFF);
  m_snake->dead_color = Color::Red;
}

void MainState::handle_input (const KeyPressed &key)
{
  m_snake->handle_input (key);
}
} // namespace Capstone
