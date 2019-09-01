
#ifndef CPP_SNAKE_GAME_SDL_GAME_FONT_BUILDER_HPP
#define CPP_SNAKE_GAME_SDL_GAME_FONT_BUILDER_HPP

#include <map>
#include "../core/game_font.hpp"

namespace SDL
{

/**
 * This struct defines the behavior of each font used in SDL's version
 * of the game.
 */
struct FontDescription
{
  std::string path;
  Capstone::Color color;
  unsigned int size;
};

/**
 * This class defines a Builder-like design pattern. It allows the
 * Game class to create a font without to "know" the logic used in
 * the SDL version to do it.
 */
class GameFontBuilder: public Capstone::GameFont {
 public:
  /**
   * This method allows the current class map each font used on game.
   *
   * The FontDescription defines the font's behavior and assign it
   * to the font map. Using the map, the current class can create a
   * Font class with some fixed attributes, such as color, size and type.
   *
   * @param theme             The theme enum used to create the font pattern under the hoods
   * @param size              The size enum used to create the font pattern under the hoods
   * @param font_description  The class that describes the font behavior.
   */
  void set_font(const Capstone::FontTheme& theme, const Capstone::FontSize& size, const FontDescription font_description);

  /**
   * This creates a configured Font class using the SDL's logic
   * defined previously
   *
   * It uses the definition assigned by `set_font` method to return
   * a well configures Font's smart pointer on GameState through
   * the Game class.
   *
   * @param theme  The theme enum used to create the font pattern under the hoods
   * @param size   The size enum used to create the font pattern under the hoods
   * @return std::unique_ptr<Capstone::Font>  The smart pointer to the configured Font class
   */
  std::unique_ptr<Capstone::Font> create (Capstone::FontTheme&& theme, Capstone::FontSize&& size) const override;

 private:

  /**
   * Hold the info of the fonts configured by set_font method.
   */
  std::map<std::pair<Capstone::FontTheme, Capstone::FontSize>, FontDescription> m_font_map;
};
} // namespace SDL

#endif // CPP_SNAKE_GAME_SDL_GAME_FONT_BUILDER_HPP
