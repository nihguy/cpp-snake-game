
#ifndef CPP_SNAKE_GAME_CORE_BUTTON_CHOOSER_HPP
#define CPP_SNAKE_GAME_CORE_BUTTON_CHOOSER_HPP

#include <functional>
#include "game_object.hpp"
#include "font.hpp"
#include "controller.hpp"

namespace Capstone
{

/**
 * This tries to imitate a Command design pattern, allowing a font
 * execute a command defined as a function.
 */
class Button
{
 public:
  /**
   * Parametrized constructor
   *
   * This defines a font to be displayed on screen and a command to be
   * executed, simulating a button behavior.
   *
   * @param font     This defines a well configured font.
   * @param command  This defines a function to be executed when necessary
   */
  Button(std::unique_ptr<Font> font, const std::function<void()>&& command);

  /**
   * This executes the function defined on constructor
   *
   * It allows a font can be used to execute a command, without creating
   * a brand new class to encapsulate this behavior.
   */
  void execute();

 public:
  /**
   * This saves the original font color, so if it changes
   * it's possible to rollback when necessary.
   */
  Color color;

  /**
   * This hold the font to be displayed as Button label.
   */
  std::unique_ptr<Font> font;

 protected:
  /**
   * This defines the command to be dispatched when the `execute` method
   * is invoked.
   */
  std::function<void()> m_command;
};

/**
 * This class allows a font to behave like a button, executing
 * a command when necessary.
 */
class ButtonChooser: public GameObject
{
 public:
  /**
   * Default constructor
   */
  ButtonChooser();

  /**
   * Destructor
   */
  virtual ~ButtonChooser() = default;

  /**
   * This updates the Button behavior
   *
   * It ensures the Button in focus will assume the "active" color,
   * and the last selected will back their original color as well.
   *
   * @param delta_time  The elapsed time between each GameLoop
   */
  void update (std::size_t delta_time) override;


  /**
   * This render the Button
   *
   * It renders all Button on the vector.
   *
   * @param renderer  The renderer instance
   */
  void render (Renderer& renderer) override;

  /**
   * This prepares the Buttons to be rendered
   *
   * It assigns the active color, to the first button on the vector.
   *
   * @param renderer  The renderer instance
   */
  void prepare (Renderer& renderer) override;

  /**
   * It allows the current class to define its own input handler
   *
   * It ensures the Button can be selected and executed properly.
   *
   * @param key  The command dispatched that can be used to handle the Button
   */
  void handle_input(const KeyPressed &key);

  /**
   * This creates a Button.
   *
   * This adds a font and a function, mixing them to create a button and
   * push them to the vector.
   *
   * @param font     The font smart pointer to represent the Button label
   * @param command  The command used to create the Button behavior when dispatched
   */
  void add_button(std::unique_ptr<Font> font, const std::function<void()>&& command);

 public:
  /**
   * This defines the Button's color is focus
   */
  Color active;

 protected:
  /**
   * The index of the activated button on vector
   */
  int m_cursor;

  /**
   * The button vector
   */
  std::vector<Button> m_buttons;
};
} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_BUTTON_CHOOSER_HPP
