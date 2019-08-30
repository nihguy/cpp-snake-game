
#ifndef CPP_SNAKE_GAME_ACTOR_SNAKE_HPP
#define CPP_SNAKE_GAME_ACTOR_SNAKE_HPP

#include <vector>

#include "../core/block.hpp"
#include "../core/controller.hpp"
#include "../core/game_thread.hpp"

namespace Capstone
{

/**
 * This is the main GameObject in the game.
 *
 * The player can handle the GameObject using the keyboard
 */
class Snake: public GameThread, public fAllocation {
 public:

  /**
   * It defines the four possible direction
   */
  enum class Direction { kUp, kDown, kLeft, kRight };

  /**
   * Default constructor
   */
  Snake();

  /**
   * This updates the snakes behavior
   *
   * It controls all the Snake behavior
   *
   * @param delta_time  The elapsed time between each GameLoop
   */
  void update(std::size_t delta_time) override;

  /**
   * This returns the current SnakeStatus
   *
   * It changes always the Snake collides with another GameObject
   *
   * @return SnakeStatus  The SnakeStatus dispatched on collision
   */
  const SnakeStatus get_status () const override;

  /**
   * This render the Snake's head and body
   *
   * @param renderer  The renderer instance
   */
  void render(Renderer &renderer) override;

  /**
   * This prepares the Snake to be rendered.
   *
   * @param renderer  The renderer instance
   */
  void prepare(Renderer &renderer) override;

  /**
   * This creates the own input handler.
   *
   * It allows the Snake easily to change direction
   *
   * @param key  The key pressed by the user
   */
  void handle_input(const KeyPressed & key);

  /**
   * This alerts the Snake to add a Block to their body vector.
   */
  void growing();

  /**
   * This allows the GameThread inherited class to assign the correct
   * SnakeStatus to the Snake.
   *
   * @param status  The SnakeStatus dispatched when Snake collides
   */
  void set_status(SnakeStatus &&status);

  /**
   * Reset the Snake
   */
  void reset();

 public:
  /**
   * The Snake's body vector
   */
  std::vector<Block> body;

  /**
   * This defines the Snake's body and head default color
   */
  Color body_color;
  Color head_color;


 private:
  /**
   * The current Snake direction
   */
  Direction m_direction = Direction::kUp;

  /**
   * This allows the Snake to avoid change the position to the opposite
   * direction.
   *
   * @param input  The expected direction
   * @param oposite  The avoided opposite direction
   */
  void change_direction(const Direction input, const Direction oposite);


  /**
   * This add a Block to the Snake's body
   *
   * This will grow the body using the previous head offset
   * @param offset  The previous Snake's head offset
   */
  void push (const iVector2&& offset);

  /**
   * This checks collision between Snake's head and body
   *
   * It's executed in another thread
   */
  void shared_check_collision ();

  /**
   * This update the Snake's position
   *
   * The method uses the direction to increment the speed to the correct
   * coordinate.
   */
  void update_head();

 private:
  /**
   * This keeps a reference to the game grid size. It's useful to warp
   * the Snake when it collides with the window border.
   */
  iVector2 m_grid;

  /**
   * This hold the Snake's speed. It increases while the Snake's growing.
   */
  float m_speed;

  /**
   * This holds if the Snake should grow.
   */
  bool m_growing;

  /**
   * This defines the Snake's status
   *
   * It changes the value when Snake collides with another GameObject
   */
  SnakeStatus m_status;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_ACTOR_SNAKE_HPP
