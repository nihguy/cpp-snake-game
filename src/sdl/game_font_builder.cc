
#include "game_font_builder.hpp"
#include "typography.hpp"

namespace SDL
{

// This defines each font pattern used on game
void GameFontBuilder::set_font (const Capstone::FontTheme& theme, const Capstone::FontSize& size, const FontDescription font_description)
{
  m_font_map[std::make_pair (theme, size)] = font_description;
}

// This returns each font pattern used on game
std::unique_ptr<Capstone::Font> GameFontBuilder::create (Capstone::FontTheme&& theme, Capstone::FontSize&& size) const
{
  auto font = m_font_map.find(std::make_pair (theme, size));

  // This throw and error if the font is not assigned to the map.
  if (font == m_font_map.end())
  {
    throw std::runtime_error("A font is not correct assigned to the GameFontBuilder::set_font(...) method.");
  }

  auto font_description = font->second;
  auto font_instance = std::make_unique<Capstone::Font> (new Typography(font_description.path, font_description.size));
  font_instance->color = font_description.color;

  return std::move(font_instance);
}
} // namespace SDL
