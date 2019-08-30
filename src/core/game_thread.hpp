
#ifndef CPP_SNAKE_GAME_CORE_GAME_THREAD_HPP
#define CPP_SNAKE_GAME_CORE_GAME_THREAD_HPP

#include <thread>
#include <vector>
#include <mutex>

#include "vector2.hpp"
#include "game_object.hpp"

namespace Capstone
{

/**
 * This defines the possible status used to each object to interact
 * with Snake GameObject
 */
enum class SnakeStatus
{
  kWalking,
  kColliding,
  kEating
};

/**
 * This ensures the thread and mutex and a thread barrier for the
 * GameObject inherited from this class.
 */
class GameThread: public GameObject {
 public:

  /**
   * Destructor
   *
   * This creates a thread barrier for the inherited classes
   */
  virtual ~GameThread();

  /**
   * Get the status on collision
   *
   * It ensures the inherited class will returns the status on collision.
   *
   * @return SnakeStatus   The status dispatched by the GameThread collision
   */
  virtual const SnakeStatus get_status () const = 0;

 protected:
  /**
   * This holds all thread that have been launched within this
   * object
   */
  std::vector<std::thread> m_threads;

  /**
   * This defines the mutex shared by all objects for protecting
   * them from unexpected external modifications
   */
  static std::mutex m_mutex;
};
} // namespace Capstone


#endif // CPP_SNAKE_GAME_CORE_GAME_THREAD_HPP
