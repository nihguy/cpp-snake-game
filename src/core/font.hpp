
#ifndef CPP_SNAKE_GAME_CORE_FONT_HPP
#define CPP_SNAKE_GAME_CORE_FONT_HPP

#include "game_object.hpp"

namespace Capstone
{

class Font;

/**
 * This class allows a third part library to create the Font's logic
 */
class Typography {
 public:

  /**
   * Destructor
   */
  virtual ~Typography () = default;

  /**
   * This allows the third party font class to prepare their
   * own renderer to use the font correctly.
   *
   * @param renderer   The Renderer class reference
   */
  virtual void prepare(Renderer &renderer) = 0;

  /**
   * This creates a texture from font's text to save memory
   *
   * @param font  The Font's class reference
   */
  virtual void create_texture(Font& font) = 0;

  /**
   * This renders the font properly
   *
   * @param font  The Font's class reference
   */
  virtual void get(const Font &font) const = 0;


  /**
   * This creates the third party library logic
   *
   * @param font  The Font's class reference
   */
  virtual void update (Font &font) = 0;
};

/**
 * It ensures the Game can use the Font without "know" what's
 * the library in use.
 */
class Font: public GameObject, public iAllocation
{
 public:

  /**
   * This allows the current class to use external Typography
   *
   * Each library can implement their own Typography rules and define
   * use with Font class easily.
   *
   * @param typography  The third part library Font's logic
   */
  Font(Typography *typography);

  /**
   * This deletes the Typography pointer properly.
   */
  virtual ~Font ();

  /**
   * This updates the font behavior
   *
   * @param delta_time The elapsed time since the last frame
   */
  void update (std::size_t delta_time) override;

  /**
   * This renders the font properly
   *
   * @param renderer  The Renderer class reference
   */
  void render (Renderer& renderer) override;

  /**
   * This prepares the font to be rendered
   *
   * @param renderer  The Renderer class reference
   */
  void prepare (Renderer& renderer) override;

  /**
   * This defines the text to be rendered
   *
   * @param text  The text to be rendered properly
   */
  void set_text(const std::string& text);

  /**
   * This returns the text assigned to the font
   *
   * @return std::string  The text assigned to the font
   */
  std::string get_text() const;

 public:

  /**
   * This defines the color of the font.
   *
   * It's useful to change the color of the text and to define
   * transparency as well.
   */
  Color color;

 protected:

  /**
   * The text to be rendered by font
   */
  std::string m_text;

  /**
   * The external Font's logic
   *
   * It allows the font to use external library logic ti be rendered.
   */
  Typography* m_typography;
};
} // namespace Capstone


#endif // CPP_SNAKE_GAME_CORE_FONT_HPP
