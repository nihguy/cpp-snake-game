
#ifndef CPP_SNAKE_GAME_CORE_BLOCK_HPP
#define CPP_SNAKE_GAME_CORE_BLOCK_HPP

#include "renderer.hpp"
#include "allocation.hpp"
#include "game_object.hpp"

namespace Capstone
{
class Block: public iAllocation, public GameObject
{
 public:
  /**
   * Default constructor
   */
  Block();

  /**
   * Parameterized constructor
   *
   * @param size  The height and the width of the object
   * @param offset  The horizontal and vertical offset of the object
   */
  explicit Block(iVector2 size, iVector2 offset);

  /**
   * This method is implemented to supply GameObject interface,
   * but it's not used by Block class
   *
   * @param delta_time  The elapsed time since the last game loop
   */
  void update(std::size_t delta_time) override;

  /**
   * This renders the current GameObject
   *
   * It allows the current class to define the GameObject color and
   * display it on the screen.
   *
   * @param renderer  The common Renderer instance
   */
  void render(Renderer &renderer) override;

  /**
   * This method is implemented to supply GameObject interface,
   * but it's not used by Block class
   *
   * @param Renderer  The common Renderer instance
   */
  void prepare(Renderer &renderer) override;

 public:
  /**
   * This defines the color of the current GameObject.
   */
  Color color;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_BLOCK_HPP
