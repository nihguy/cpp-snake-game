#include "snake.hpp"
#include <cmath>
#include <iostream>


namespace Capstone
{

void Snake::update ()
{
  // We first capture the head's cell before updating.
  auto prev_cell = iVector2(head);
  update_head();

  // Capture the head's cell after updating.
  auto current_cell = iVector2(head);

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
  {
    update_body(current_cell, prev_cell);
  }
}

void Snake::update_head ()
{
  switch (direction)
  {
    case Direction::kUp:
      head.y -= speed;
      break;

    case Direction::kDown:
      head.y += speed;
      break;

    case Direction::kLeft:
      head.x -= speed;
      break;

    case Direction::kRight:
      head.x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head.x = fmod(head.x + m_grid.x, m_grid.x);
  head.y = fmod(head.y + m_grid.y, m_grid.y);
}

void Snake::update_body (iVector2 &current_head_cell, iVector2 &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!m_growing)
  {
    // Remove the tail from the vector.
    body.erase(body.begin());
  }
  else
  {
    m_growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body)
  {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y)
    {
      alive = false;
    }
  }
}

void Snake::grow_body ()
{
  m_growing = true;
}

// Inefficient method to check if cell is occupied by snake.
bool Snake::snake_cell (iVector2 offset)
{
  if (offset == iVector2(head))
  {
    return true;
  }

  for (auto const &item : body)
  {
    if (offset == item)
    {
      return true;
    }
  }
  return false;
}

} // namespace Capstone
