
#ifndef CPP_SNAKE_GAME_SDL_RENDERER_HPP
#define CPP_SNAKE_GAME_SDL_RENDERER_HPP

#include <SDL2/SDL.h>

#include "../core/renderer.hpp"

namespace SDL
{

/**
 * This creates the Renderer specific to SDL library
 */
class Renderer: public Capstone::Renderer {
 public:

  /**
   * Parametrized constructor
   *
   * @param screen  The height and width of the game screen
   * @param grid  The total number of vertical and horizontal grids
   */
  Renderer(const Capstone::iVector2& screen, const Capstone::iVector2& grid);

  /**
   * Destructor
   *
   * This destroys the SDL_Renderer and SDL_Window pointers
   */
  ~Renderer () override;

  /**
   * This clear the screen using the color assigned as argument
   *
   * @param color  The Color used to paint the screen
   */
  void clear(const Capstone::Color &color) const override;

  /**
   * This fill the color to be used by the object on screen
   *
   * @param color  The color used by the GameObject
   */
  void fill_color(const Capstone::Color &color) const override;

  /**
   * This defines fill the object with the color and prepares
   * it to be renderer by display method.
   *
   * @param allocation  The place where the GameObject should be rendered
   */
  void fill(const Capstone::iAllocation &allocation) const override;

  /**
   * This render the object properly
   *
   * It's the final step to ensures the GameObject will be displayed
   * on the screen.
   */
  void display() const override;

  /**
   * This returns the grid height and the width values
   *
   * @return iVector2  The height and width value in x and y coordinates
   */
  const Capstone::iVector2 get_grid () const override;

  /**
   * This returns the screen height and the width values
   *
   * @return iVector2  The height and width value in x and y coordinates
   */
  const Capstone::iVector2 get_screen () const override;
 public:
  /**
   * This holds the Renderer and Window from SDL.
   * They both are the main class used to display the GameObject on
   * screen.
   */
  SDL_Renderer *renderer;
  SDL_Window *window;

 protected:
  /**
   * This defines the grid measures
   */
  const Capstone::iVector2 m_screen;

  /**
   * This defines the number of grid used along the screen
   */
  const Capstone::iVector2 m_grid;
};
} // namespace SDL

#endif //CPP_SNAKE_GAME_SDL_RENDERER_HPP
