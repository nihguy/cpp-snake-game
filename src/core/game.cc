#include "game.hpp"
#include <iostream>
#include <SDL2/SDL_timer.h>

namespace Capstone
{

Game::Game (std::size_t grid_width, std::size_t grid_height):
  snake (grid_width, grid_height),
  engine (dev()),
  random_w (0, static_cast<int>(grid_width)),
  random_h (0, static_cast<int>(grid_height))
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
    controller.handle_input (running, snake);
    update ();
    renderer.render (snake, food);

    frame_end = SDL_GetTicks ();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.update_window_title (score, frame_count);
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
    x = random_w(engine);
    y = random_h(engine);

    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.snake_cell(x, y))
    {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::update()
{
  if (!snake.alive) return;

  snake.update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y)
  {
    score++;
    place_food();
    // Grow snake and increase speed.
    snake.grow_body();
    snake.speed += 0.02;
  }
}

int Game::get_score() const
{
  return score;
}

int Game::get_size () const
{
  return snake.size;
}

} // namespace Capstone
