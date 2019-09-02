
#include "button_chooser.hpp"

namespace Capstone
{

// This creates a Button using a font and a function
Button::Button (std::unique_ptr<Font> font, const std::function<void ()>&& command):
  font{std::move(font)},
  m_command{command}
{

}

// This executes the defined Button command
void Button::execute ()
{
  m_command();
}


// This defines the first button on vector as the active one
ButtonChooser::ButtonChooser ():
    m_cursor{0},
    active{Color(0xFFCC00FF)}
{

}

void ButtonChooser::update (std::size_t delta_time)
{
  // This ensures the buttons will update their colors
  for (auto &button: m_buttons)
  {
    button.font->update (delta_time);
  }
}

// This renders the buttons
void ButtonChooser::render (Renderer& renderer)
{
  for (auto &button: m_buttons)
  {
    button.font->render (renderer);
  }
}

void ButtonChooser::prepare (Renderer& renderer)
{
  // It stores the original font color. It's useful when the cursor
  // moves, selecting a new Button as active and the previous one need
  // to back to the original color.
  for (auto &button: m_buttons)
  {
    button.color = button.font->color;
  }

  // This defines the first button as the active one
  m_buttons[m_cursor].font->color = active;
}


void ButtonChooser::handle_input (const KeyPressed &key)
{
  if (key == KeyPressed::kUp || key == KeyPressed::kDown)
  {
    // This back the original color to the previous button in focus
    m_buttons[m_cursor].font->color = m_buttons[m_cursor].color;
  }

  switch (key)
  {
    // This defines a vertical carousel effect to select the Button in focus
    case KeyPressed::kUp:
      if (m_cursor == 0) m_cursor = static_cast<int>(m_buttons.size());
      --m_cursor;
      break;

    // This defines a vertical carousel effect to select the Button in focus
    case KeyPressed::kDown:
      ++m_cursor;
      break;

    // This execute the Button in focus
    case KeyPressed::kEnter:
      m_buttons[m_cursor].execute ();
      return;
  }

  // This defines the cursor of the button in focus
  m_cursor = m_cursor % static_cast<int>(m_buttons.size());
  m_buttons[m_cursor].font->color = active;
}


void ButtonChooser::add_button (std::unique_ptr<Font> font, const std::function<void ()>&& command)
{
  // This creates a Button and push it to the vector
  m_buttons.emplace_back (Button(std::move(font), std::move(command)));
}
} // namespace Capstone
