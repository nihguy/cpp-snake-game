#ifndef CPP_SNAKE_GAME_CORE_RENDERER_HPP
#define CPP_SNAKE_GAME_CORE_RENDERER_HPP

#include <vector>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

#include "../actor/snake.hpp"
#include "color.hpp"

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
  SDL_Window *m_sdl_window;
  SDL_Renderer *m_sdl_renderer;

  const std::size_t m_screen_width;
  const std::size_t m_screen_height;
  const std::size_t m_grid_width;
  const std::size_t m_grid_height;

  // Colors
  Color m_window_color;
  Color m_snake_head_color;
  Color m_snake_body_color;
  Color m_snake_died_color;
  Color m_food_color;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_RENDERER_HPP