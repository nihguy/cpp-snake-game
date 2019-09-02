
#include "font_maker.hpp"

namespace SDL
{

// It creates the font pattern used by SDL version of the game
FontDescription font_maker (const Capstone::FontTheme& theme, const Capstone::FontSize& size)
{
  FontDescription font_description;
  font_description.color =  Capstone::Color::Black;

  switch(size)
  {
    case Capstone::FontSize::kSmall:
      font_description.path = "resources/fonts/BitPotion.ttf";
      font_description.size = 50;

      if (theme == Capstone::FontTheme::kDark)
      {
        font_description.color = Capstone::Color(0xF0F7F4FF);
      }
      else
      {
        font_description.color = Capstone::Color(0x333333FF);
      }
      break;

    case Capstone::FontSize::kMedium:
      font_description.path = "resources/fonts/PressStart2P.ttf";
      font_description.size = 30;

      if (theme == Capstone::FontTheme::kDark)
      {
        font_description.color = Capstone::Color(0x99E1D9FF);
      }
      break;

    case Capstone::FontSize::kLarge:
      font_description.path = "resources/fonts/PressStart2P.ttf";
      font_description.size = 30;

      if (theme == Capstone::FontTheme::kDark)
      {
        font_description.color = Capstone::Color(0x99E1D9FF);
      }
      break;
  }

  return font_description;
}

} // namespace SDL