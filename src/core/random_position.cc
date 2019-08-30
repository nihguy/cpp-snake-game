
#include "random_position.hpp"

namespace Capstone
{

// Parametrized constructor
// Create the random number to be used by the axes position
RandomPosition::RandomPosition (const iVector2& delimiter):
  m_engine(m_dev()),
  m_random(0, RAND_MAX),
  delimiter(delimiter)
{

}
int RandomPosition::get_x ()
{
  // This defines a random between zero and the value defined as max.x
  return m_random(m_engine) % (delimiter.x - 1);
}

int RandomPosition::get_y ()
{
  // This defines a random between zero and the value defined as max.y
  return m_random(m_engine) % (delimiter.y - 1);
}

iVector2 RandomPosition::get ()
{
  // This defines a random Vector2<int> between zero and the value defined
  // on delimiter variable
  return {
    get_x (),
    get_y ()
  };
}

} // namespace Capstone
