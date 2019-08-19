#include "game.hpp"
#include <iostream>
#include <SDL2/SDL_timer.h>

namespace Capstone
{

Game::Game (std::size_t grid_width, std::size_t grid_height):
  m_snake (grid_width, grid_height),
  m_engine (m_dev()),
  m_random_w (0, static_cast<int>(grid_width)),
  m_random_h (0, static_cast<int>(grid_height))
{
  place_food();
}

void Game::run (Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.handle_input (running, m_snake);
    update ();
    renderer.render (m_snake, m_food);

    frame_end = SDL_GetTicks ();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.update_window_title (m_score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay (target_frame_duration - frame_duration);
    }
  }
}

void Game::place_food ()
{
  int x, y;
  while (true)
  {
    x = m_random_w(m_engine);
    y = m_random_h(m_engine);

    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!m_snake.snake_cell(x, y))
    {
      m_food.x = x;
      m_food.y = y;
      return;
    }
  }
}

void Game::update()
{
  if (!m_snake.alive) return;

  m_snake.update();

  int new_x = static_cast<int>(m_snake.head_x);
  int new_y = static_cast<int>(m_snake.head_y);

  // Check if there's food over here
  if (m_food.x == new_x && m_food.y == new_y)
  {
    m_score++;
    place_food();
    // Grow snake and increase speed.
    m_snake.grow_body();
    m_snake.speed += 0.02;
  }
}

int Game::get_score() const
{
  return m_score;
}

int Game::get_size () const
{
  return m_snake.size;
}

} // namespace Capstone
