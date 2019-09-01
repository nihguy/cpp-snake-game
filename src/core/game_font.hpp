
#ifndef CPP_SNAKE_CORE_GAME_FONT_HPP
#define CPP_SNAKE_CORE_GAME_FONT_HPP

#include "font.hpp"

namespace Capstone
{

/**
 * This defines the font size that could be used on game
 */
enum class FontSize
{
  kExtraSmall,
  kSmall,
  kMedium,
  kLarge
};

/**
 * This defines the themes that could be used on game
 */
enum class FontTheme
{
  kDark,
  kLight
};

/**
 * This class is used by Game to return the correct font using its
 * get_font method.
 *
 * It's useful to uncouple the logic of the current library to get
 * the font properly.
 *
 */
class GameFont {
 public:
  /**
   * This enforces the inherited class to offset a simple way to return
   * the expected font using the FontTheme and the FontSize. It allows
   * the GameState to use the font without "know" their real attributes
   * like color, size or the method used to create that.
   *
   * @param theme  This allows an external class to defines the font
   *               attributes such as color and font name
   * @param size   This alloes an external class to defines the font
   *               attributes such as size and font name
   * @return std::unique_ptr<Font>  The smart pointer of the "configured" font
   */
  virtual std::unique_ptr<Font> create(FontTheme &&theme, FontSize &&size) const = 0;
};

} // namespace Capstone


#endif // CPP_SNAKE_CORE_GAME_FONT_HPP
