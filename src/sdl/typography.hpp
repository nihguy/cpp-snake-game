
#ifndef CPP_SNAKE_GAME_SDL_TYPOGRAPHY_HPP
#define CPP_SNAKE_GAME_SDL_TYPOGRAPHY_HPP

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

#include "../core/font.hpp"
#include "renderer.hpp"

namespace SDL
{
/**
 * This allows the GameState inherited class to use the SDL's Font
 * logic.
 *
 * It creates a texture of the font's text to save memory. This way,
 * the Allocations variables will change the texture data, instead
 * the "raw" font properly.
 */
class Typography: public Capstone::Typography {
 public:

  /**
   * Parametrized constructor
   *
   * This creates a SDL's font using the size and the relative path
   * to the font file.
   *
   * @param path  The relative path to the font file
   * @param size  The size of the expected font
   */
  Typography(const std::string& path, unsigned int size);

  /**
   * This defines the destructor
   *
   * It destroys the SDL's pointer created to execute the expected
   * behavior.
   */
  ~Typography () override;

  /**
   * This prepared the Renderer, converting it to SDL::Renderer class.
   *
   * @param renderer  The Font class reference
   */
  void prepare (Capstone::Renderer& renderer) override;

  /**
   * This creates the texture from SDL's font text.
   *
   * It's useful to save memory. Rendering the font at each GameLoop is
   * pretty expensive, so we create a texture, using the font's text
   * to save memory.
   *
   * @param font  The Font class reference
   */
  void create_texture (Capstone::Font& font) override;

  /**
   * This render the texture created from SDL's font text.
   *
   * This should be used on Font's render method. It not use the common
   * Renderer's `fill` method to be rendered.
   *
   * @param font  The Font class reference
   */
  void get (const Capstone::Font& font) const override;

  /**
   * This checks if the attributes used by the font properly has changed.
   *
   * It checks if the text and the color of the Font class was altered
   * from the last time.
   *
   * @param font  The Font class reference
   */
  void update (Capstone::Font& font) override;

 protected:

  /**
   * The pointer of the SDL's font properly
   */
  TTF_Font *m_font;

  /**
   * It holds the Renderer pointer. As the current class need to create
   * a texture on GameState's update method, we need to keep it accessible.
   *
   * It broke the GameState logic, because the class expect the Renderer
   * should be accessed on `prepare` and `render` methods, but it's necessary
   * once the SDL's font is not rendered as "ordinary" classes.
   */
  Renderer *m_renderer;

  /**
   * It's created to save memory because to render the font directly is
   * pretty expensive.
   */
  SDL_Texture *m_texture;

  /**
   * This holds the color assigned to the Capstone::Font on the last
   * GameLoop. It allows the current class to check if the color changed
   * between each frame and recreate the font's texture always a change
   * is identified
   */
  Capstone::Color m_color;

  /**
   * This holds the text assigned to the Capstone::Font on the last
   * GameLoop. It allows the current class to check if the text changed
   * between each frame and recreate the font's texture always a change
   * is identified
   */
  std::string m_text;
};
} // namespace SDL


#endif //CPP_SNAKE_GAME_SDL_TYPOGRAPHY_HPP
