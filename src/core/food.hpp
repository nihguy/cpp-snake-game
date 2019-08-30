
#ifndef CPP_SNAKE_GAME_CORE_FOOD_HPP
#define CPP_SNAKE_GAME_CORE_FOOD_HPP

#include <future>
#include "game_thread.hpp"
#include "block.hpp"
#include "../actor/snake.hpp"
#include "random_position.hpp"

namespace Capstone
{

/**
 * This defines the thread instance of Block to be used as food's GameObject
 *
 * All the food behavior is contained is this class.
 */
class Food: public GameThread
{
 public:
  /**
   * This replaces the food offset using thread
   *
   * It should be invoked to start the `replace_food` protected method
   * using "local" thread.
   */
  void replace();

  /**
   * This prepares the food to be rendered
   *
   * It creates the common behavior of the food such as color, position
   * and start the `shared_check_collision` method using thread as well.
   *
   * @param renderer  The renderer instance
   */
  void prepare(Renderer &renderer) override;

  /**
   * This render the food
   *
   * It just execute the Block's render method properly
   *
   * @param renderer  The renderer instance
   */
  void render(Renderer &renderer) override;

  /**
   * This updates the food behavior
   *
   * It just execute the Block's update method properly
   *
   * @param delta_time  The elapsed time between each GameLoop
   */
  void update (std::size_t delta_time) override;

  /**
   * This returns the SnakeStatus used when colliding
   *
   * The food returns SnakeStatus::kEating when it collides with
   * the Snake.
   *
   * @return SnakeStatus  This is always SnakeStatus::kEating
   */
  const SnakeStatus get_status () const  override;

  /**
   * This assign the Snake smart pointer
   *
   * It ensures the Snake used on game can be used on check_collision properly
   *
   * @param target
   */
  void set_target (std::shared_ptr<Snake> target);

 private:

  /**
   * This defines the collision check of the food
   *
   * It uses a thread to allows the food to dispatch the SnakeStatus::kEating
   * always both, the food and snake are colliding.
   */
  void shared_check_collision ();

  /**
   * This ensures the food only will be placed in a void "grid space"
   *
   * The method will be executed using a std::async and should not be
   * invoked directly.
   *
   * @param snake  The "m_target" shared pointer of this class
   * @param random  The "m_random" shared pointer of this class
   * @return iVector2  The offset that don't collide with snake's head and body
   */
  iVector2 replace_food (const std::shared_ptr<Snake>& snake, std::shared_ptr<RandomPosition> random);

 private:

  /**
   * This defines the Block used as food on screen
   */
  std::shared_ptr<Block> m_food;

  /**
   * This defines the class to get random position
   */
  std::shared_ptr<RandomPosition> m_random;

  /**
   * This defines the main actor used on the game
   */
  std::shared_ptr<Snake> m_target;
};
} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_FOOD_HPP
