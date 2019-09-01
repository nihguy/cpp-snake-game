
#include <SDL2/SDL_rect.h>

#include "typography.hpp"

namespace SDL
{

Typography::Typography (const std::string& path, unsigned int size)
{
  m_font = TTF_OpenFont (path.c_str (), size);

  if (m_font == nullptr)
  {
    printf("The font %s with size %d can not be loaded. SDL_ttf Error: %s", path.c_str (), size, TTF_GetError());
    SDL_Quit();
  }
}

// This destroys the SDL pointer used on class.
Typography::~Typography ()
{
  TTF_CloseFont(m_font);
  SDL_DestroyTexture (m_texture);
}

// This converts the Capstone::Renderer to SDL::Renderer
void Typography::prepare (Capstone::Renderer &renderer)
{
  m_renderer = dynamic_cast<SDL::Renderer*>(&renderer);
}

// This creates the texture using the Font's text
void Typography::create_texture (Capstone::Font& font)
{
  m_text = font.get_text ();
  m_color = font.color;

  if (m_texture != nullptr)
  {
    SDL_DestroyTexture (m_texture);
  }

  SDL_Color sdl_color { m_color.r, m_color.g, m_color.b, m_color.a };
  SDL_Surface* surface = TTF_RenderText_Solid(m_font, m_text.c_str(), sdl_color);

  if(surface == nullptr)
  {
    printf ("Unable to render text surface! SDL_ttf Error: %s", TTF_GetError());
    SDL_Quit();
  }

  // create a image from surface
  m_texture = SDL_CreateTextureFromSurface (m_renderer->renderer, surface);

  font.size.x = surface->w;
  font.size.y = surface->h;

  SDL_FreeSurface (surface);
}

// It's not use the grid system to render the font, so the conventional
// Allocation class is not used.
void Typography::get (const Capstone::Font& font) const
{
  SDL_Rect destination = {
    font.offset.x,
    font.offset.y,
    font.size.x,
    font.size.y,
  };

  SDL_RenderCopy(m_renderer->renderer, m_texture, nullptr, &destination);
}

// This forces the texture redraw when the color or the text has changed
void Typography::update (Capstone::Font& font)
{
  if (font.color != m_color || font.get_text () != m_text)
  {
    create_texture(font);
  }
}

} // namespace SDL
