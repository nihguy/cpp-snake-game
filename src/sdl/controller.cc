
#include <SDL_events.h>
#include "controller.hpp"

namespace SDL
{

Capstone::KeyPressed Controller::handle_input (bool& running)
{
  SDL_Event event;

  // Ensures the GameState in focus can manipulate their own events and,
  // allows `is_running` changes their value by SDL_QUIT event dispatch
  while (SDL_PollEvent (&event))
  {
    if (event.type == SDL_QUIT)
    {
      running = false;
    }

    if (event.key.type == SDL_KEYDOWN)
    {
      // this defines the return as enter and the arrows as
      // "directional" inputs
      switch (event.key.keysym.sym)
      {
        case SDLK_KP_ENTER:
        case SDLK_RETURN:
          return Capstone::KeyPressed::kEnter;
        case SDLK_UP:
          return Capstone::KeyPressed::kUp;
        case SDLK_LEFT:
          return Capstone::KeyPressed::kLeft;
        case SDLK_DOWN:
          return Capstone::KeyPressed::kDown;
        case SDLK_RIGHT:
          return Capstone::KeyPressed::kRight;
      default:
        return Capstone::KeyPressed::kUndefined;
      }
    }
  }

  return Capstone::KeyPressed::kUndefined;
}
} // namespace SDL

