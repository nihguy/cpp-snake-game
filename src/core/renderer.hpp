#ifndef CPP_SNAKE_GAME_CORE_RENDERER_HPP
#define CPP_SNAKE_GAME_CORE_RENDERER_HPP

#include "color.hpp"
#include "vector2.hpp"
#include "allocation.hpp"

// Todo: remover
#include <iostream>
#include <memory>

namespace Capstone
{

class GameState;

/**
 * This defines the interface to access the main function on
 * the graphical library abstraction.
 */
class Renderer
{
 public:

  /**
   * Destructor
   */
  virtual ~Renderer () = default;

  /**
   * This clear the screen using the color assigned as argument
   *
   * @param color  The Color used to paint the screen
   */
  virtual void clear(const Color &color) const = 0;

  /**
   * This fill the color to be used by the object on screen
   *
   * @param color  The color used by the GameObject
   */
  virtual void fill_color(const Color &color) const = 0;

  /**
   * This defines fill the object with the color and prepares
   * it to be renderer by display method.
   *
   * @param allocation  The place where the GameObject should be rendered
   */
  virtual void fill(const iAllocation &allocation) const = 0;

  /**
   * This render the object properly
   *
   * It's the final step to ensures the GameObject will be displayed
   * on the screen.
   */
  virtual void display() const = 0;

  /**
   * This returns the grid height and the width values
   *
   * @return iVector2  The height and width value in x and y coordinates
   */
  virtual const iVector2 get_grid() const = 0;

  /**
   * This returns the screen height and the width values
   *
   * @return iVector2  The height and width value in x and y coordinates
   */
  virtual const iVector2 get_screen() const = 0;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_RENDERER_HPP