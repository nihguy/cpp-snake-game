
#include <iostream>
#include "renderer.hpp"

namespace SDL
{

Renderer::Renderer (const Capstone::iVector2& screen, const Capstone::iVector2& grid):
  m_grid{grid},
  m_screen{screen}
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize! SDL Error:" << SDL_GetError () << std::endl;
    SDL_Quit();
  }

  // Create window
  window = SDL_CreateWindow ("Capstone Game", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, screen.x,
                             screen.y, SDL_WINDOW_SHOWN);
  if (window == nullptr)
  {
    std::cerr << "Window could not be created." << std::endl;
    std::cerr << "SDL_Error: " << SDL_GetError () << std::endl;
    SDL_Quit();
  }

  renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr)
  {
    std::cerr << "Renderer could not be created." << std::endl;
    std::cerr << "SDL_Error: " << SDL_GetError () << std::endl;
    SDL_Quit();
  }
}

Renderer::~Renderer ()
{
  // This destroys the SDL pointer used by the class.
  SDL_DestroyWindow (window);
  SDL_DestroyRenderer (renderer);
  SDL_Quit();
}

void Renderer::clear (const Capstone::Color& color) const
{
  // This clears the screen and fills with the assigned color
  fill_color (color);
  SDL_RenderClear(renderer);
}

void Renderer::fill_color (const Capstone::Color& color) const
{
  SDL_SetRenderDrawColor (renderer, color.r, color.g, color.b, color.a);
}

void Renderer::fill (const Capstone::iAllocation& allocation) const
{
  SDL_Rect rect {
    allocation.offset.x * allocation.size.x,
    allocation.offset.y * allocation.size.y,
    allocation.size.x,
    allocation.size.y,
  };

  // This prepares the GameObject to be rendered
  SDL_RenderFillRect(renderer, &rect);
}

void Renderer::display () const
{
  // This draws the GameObject on the screen
  SDL_RenderPresent (renderer);
}

const Capstone::iVector2 Renderer::get_grid () const
{
  return m_grid;
}

const Capstone::iVector2 Renderer::get_screen () const
{
  return m_screen;
}

} // namespace Capstone
