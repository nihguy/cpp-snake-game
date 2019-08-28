// Copyright 2019 <Victor Borges>

#include "snake.hpp"
#include "../core/vector2.hpp"

namespace Capstone {

Snake::Snake (iVector2 size, iVector2 offset, iVector2 grid):
  fAllocation::Allocation (fVector2(size.x, size.y), fVector2(offset.x, offset.y)),
  m_grid(grid),
  speed(0.2f),
  alive{true},
  m_growing{false}
{

}

void Snake::update (std::size_t delta_time)
{
  // We first capture the head's cell before updating
  iVector2 prev_cell = iVector2(offset);
  update_head ();

  // After update, we capture the head's cell again
  iVector2 current_cell = iVector2(offset);

  // Update all of the body vector items if the snake head has moved to a new cell
  if (current_cell != prev_cell)
  {
    update_body (current_cell, prev_cell);
  }
}

void Snake::render (Renderer& renderer)
{
  // Render snake's body
  renderer.fill_color (body_color);
  for (const Block &point: body)
  {
    renderer.fill(point);
  }

  if (alive)
  {
    renderer.fill_color (head_color);
  }
  else
  {
    renderer.fill_color (dead_color);
  }

  renderer.fill(get_allocation_as<int> ());
}

void Snake::prepare (Renderer& renderer)
{

}

void Snake::grow_body ()
{
  m_growing = true;
}

void Snake::handle_input (const KeyPressed & key)
{
  switch (key)
  {
    case KeyPressed::kUp:
      change_direction (Direction::kUp, Direction::kDown);
      break;
    case KeyPressed::kDown:
      change_direction (Direction::kDown, Direction::kUp);
      break;
    case KeyPressed::kLeft:
      change_direction (Direction::kLeft, Direction::kRight);
      break;
    case KeyPressed::kRight:
      change_direction (Direction::kRight, Direction::kLeft);
      break;
  }
}

void Snake::change_direction (const Snake::Direction input, const Snake::Direction oposite)
{
  if (direction != oposite) direction = input;
}

void Snake::update_head ()
{
  if (!alive)
  {
    return;
  }

  // Changes the head direction and accelerate it in a constant speed;
  switch(direction)
  {
    case Direction::kUp:
      offset.y -= speed;
      break;
    case Direction::kDown:
      offset.y += speed;
      break;
    case Direction::kLeft:
      offset.x -= speed;
      break;
    case Direction::kRight:
      offset.x += speed;
      break;
  }

  // Wraps the snake around to the beginning if going off the screen.
  offset.x = fmod(offset.x + m_grid.x, m_grid.x);
  offset.y = fmod(offset.y + m_grid.y, m_grid.y);
}

void Snake::update_body (iVector2& current_head_cell, iVector2& prev_head_cell)
{
  // Add previous head location to vector
  body.emplace_back (Block(iVector2(size), prev_head_cell));

  if (!m_growing)
  {
    body.erase(body.begin());
  }
  else
  {
    m_growing = false;
  }

  // Check if the snake has died
  for (const auto &item: body)
  {
    if (item.offset == current_head_cell)
    {
      alive = false;
    }
  }
}

} // namespace Capstone