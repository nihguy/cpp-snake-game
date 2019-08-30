
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
   * Parametrized constructor
   *
   * @param delimiter  This defines the delimiter variables
   */
  explicit RandomPosition(const iVector2& delimiter);

  /**
   * Get a random number
   *
   * It returns a number between zero and the number specified
   * on x's coordinate delimiter.
   *
   * @return int  The random number
   */
  int get_x();

  /**
   * Get a random number
   *
   * It returns a number between zero and the number specified
   * on y's coordinate delimiter.
   *
   * @return int  The random number
   */
  int get_y();

  /**
   * Get a random Vector2<int>
   *
   * It returns a random coordinate between zero and the number
   * specified on delimiter variable.
   */
  iVector2 get();

 public:

  /**
   * This defines the max length of each coordinate
   */
  iVector2 delimiter;
 protected:

  /**
   * The variables used to create the default C++ random behavior
   */
  std::random_device m_dev;
  std::mt19937 m_engine;
  std::uniform_int_distribution<int> m_random;
};

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_RANDOM_POSITION_HPP
