#include "controller.hpp"
#include <iostream>
#include "SDL.h"
#include "snake.hpp"

namespace Capstone
{

void Controller::change_direction (Snake &snake, Snake::Direction input,
                                   Snake::Direction opposite) const
{
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
}

void Controller::handle_input (bool &running, Snake &snake) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
        case SDLK_UP:
          change_direction (snake, Snake::Direction::kUp,
                            Snake::Direction::kDown);
          break;
        case SDLK_DOWN:
          change_direction (snake, Snake::Direction::kDown,
                            Snake::Direction::kUp);
          break;
        case SDLK_LEFT:
          change_direction (snake, Snake::Direction::kLeft,
                            Snake::Direction::kRight);
          break;
        case SDLK_RIGHT:
          change_direction (snake, Snake::Direction::kRight,
                            Snake::Direction::kLeft);
          break;
      }
    }
  }
}

} // namespace Capstone
