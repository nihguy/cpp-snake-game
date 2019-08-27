
#include "random_position.hpp"

namespace Capstone
{

// Default constructor
// Create the random number to be used by the axes position
RandomPosition::RandomPosition ():
  m_engine(m_dev()),
  m_random(0, RAND_MAX)
{

}
int RandomPosition::get_x ()
{
  // This defines a random between zero and the value defined as max.x
  return m_random(m_engine) % max.x;
}

int RandomPosition::get_y ()
{
  // This defines a random between zero and the value defined as max.y
  return m_random(m_engine) % max.y;
}

} // namespace Capstone
