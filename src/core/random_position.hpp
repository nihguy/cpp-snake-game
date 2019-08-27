
#ifndef CPP_SNAKE_GAME_CORE_RANDOM_POSITION_HPP
#define CPP_SNAKE_GAME_CORE_RANDOM_POSITION_HPP

#include <cstdlib>
#include <random>
#include "vector2.hpp"

namespace Capstone
{

/**
 * Creates a random coordinate integer that can be used to define
 * the food or obstacles on the game.
 *
 * The minimal number is always zero and the max can be assigned
 * to the Vector2's variable called `max`.
 */
class RandomPosition
{
 public:
  /**
   * Default constructor
   */
  RandomPosition();

  /**
   * Get a random number
   *
   * It returns a number between zero and the number specified
   * on x's coordinate.
   *
   * @return int  The random number
   */
  int get_x();

  /**
   * Get a random number
   *
   * It returns a number between zero and the number specified
   * on ys coordinate.
   *
   * @return int  The random number
   */
  int get_y();

  iVector2 max;
 protected:
  std::random_device m_dev;
  std::mt19937 m_engine;
  std::uniform_int_distribution<int> m_random;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_RANDOM_POSITION_HPP
