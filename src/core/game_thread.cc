
#include <algorithm>
#include "game_thread.hpp"

namespace Capstone
{

// This share the same mutex to all inherited classes
std::mutex GameThread::m_mutex;

GameThread::~GameThread ()
{
  // This set up thread barrier before this object is destroyed
  std::for_each(m_threads.begin (), m_threads.end (), [](std::thread &t)
  {
    t.join();
  });
}

} // namespace Capstone
