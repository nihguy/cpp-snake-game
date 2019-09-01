
#ifndef CPP_SNAKE_GAME_SDL_FONT_MAKER_HPP
#define CPP_SNAKE_GAME_SDL_FONT_MAKER_HPP

#include <memory>
#include "game_font_builder.hpp"

namespace SDL
{

/**
 * This returns the correct FontDescription based on arguments
 * assigned to the function
 *
 * This function holds all font's name, color and size used
 * by SDL version of the game.
 *
 * @param theme  The theme enum used to create the font pattern under the hoods
 * @param size   The size enum used to create the font pattern under the hoods
 * @return
 */
FontDescription font_maker(const Capstone::FontTheme &theme, const Capstone::FontSize &size);

} // namespace SDL

#endif // CPP_SNAKE_GAME_SDL_FONT_MAKER_HPP
