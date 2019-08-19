#include "renderer.hpp"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

namespace Capstone
{

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height):
  m_screen_width(screen_width),
  m_screen_height(screen_height),
  m_grid_width(grid_width),
  m_grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize." << std::endl;
    std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
  }

  // Create Window
  m_sdl_window = SDL_CreateWindow ("Snake Game", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, screen_width,
                                 screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == m_sdl_window)
  {
    std::cerr << "Window could not be created." << std::endl;
    std::cerr << " SDL_Error: " << SDL_GetError() << std::endl;
  }

  // Create renderer
  m_sdl_renderer = SDL_CreateRenderer(m_sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == m_sdl_renderer)
  {
    std::cerr << "Renderer could not be created." << std::endl;
    std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
  }
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(m_sdl_window);
  SDL_Quit();
}

void Renderer::render(Snake const snake, SDL_Point const &food)
{
  SDL_Rect block;
  block.w = m_screen_width / m_grid_width;
  block.h = m_screen_height / m_grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(m_sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(m_sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(m_sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(m_sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(m_sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(m_sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;

  if (snake.alive)
  {
    SDL_SetRenderDrawColor(m_sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  }
  else
  {
    SDL_SetRenderDrawColor(m_sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }

  SDL_RenderFillRect(m_sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(m_sdl_renderer);
}

void Renderer::update_window_title (int score, int fps)
{
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(m_sdl_window, title.c_str());
}

} // namespace Capstone
