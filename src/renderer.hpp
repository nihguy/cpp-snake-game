#ifndef CPP_SNAKE_GAME_RENDERER_HPP
#define CPP_SNAKE_GAME_RENDERER_HPP

#include <vector>
#include "SDL.h"
#include "snake.hpp"

namespace Capstone
{
class Renderer
{
 public:
  // Methods
  Renderer (const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer ();

  void render (Snake const snake, SDL_Point const &food);
  void update_window_title (int score, int fps);

 private:
  // Variables
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_RENDERER_HPP