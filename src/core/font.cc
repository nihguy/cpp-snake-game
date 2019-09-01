
#include "font.hpp"

namespace Capstone
{

// It adds the third party logic to the default Font's behavior
Font::Font (Typography *typography):
  m_typography{typography}
{

}

// This deletes the Typography pointer so satisfy the Udacity's Project Specification
Font::~Font ()
{
  delete m_typography;
}

// This updates the font using third party font logic.
void Font::update (std::size_t delta_time)
{
  m_typography->update (*this);
}

// This renders the font using third party font logic.
void Font::render (Renderer& renderer)
{
  m_typography->get (*this);
}

// To satisfy the SDL's font logic, the color and text font should be setted
// before the `prepare` method
void Font::prepare (Renderer& renderer)
{
  // It ensures the font dimension can be accessed correctly on GameState's `prepare` method
  if (m_text.empty ())
  {
    throw std::runtime_error("Font error: set_text() method should be invoked before preparing the class.");
  }

  m_typography->prepare (renderer);
  m_typography->create_texture (*this);
}

// This assign the text to be rendered
void Font::set_text (const std::string& text)
{
  m_text = text;
}

// This get the text to be rendered
std::string Font::get_text () const
{
  return m_text;
}

} // namespace Capstone
