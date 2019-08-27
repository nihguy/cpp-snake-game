
#include <SDL_events.h>
#include <SDL_timer.h>
#include "game_loop.hpp"


namespace SDL
{


GameLoop::GameLoop (std::size_t target_frame_duration):
  m_frame_duration{target_frame_duration}
{

}

bool GameLoop::execute (Capstone::Game& game, Capstone::Renderer &renderer, Capstone::Controller &controller) const
{
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;

  SDL_Event event;

  // Execute the game loop using a fixed time between each frame
  while (game.is_running)
  {
    frame_start = SDL_GetTicks ();

    // This ensures the GameState in focus will receive the elapsed time since
    // their last execution
    game.peek_state ()->update (m_frame_duration);

    // This allows the current GameState to manipulate their own events
    game.peek_state ()->handle_input (controller.handle_input (game.is_running));

    // This assign the same instance of Capstone::Renderer for all GameState on stack
    game.peek_state ()->render (renderer);

    frame_end = SDL_GetTicks ();
    frame_duration = frame_end - frame_start;

    // Always the execution is faster than expected, wait until FPS specified
    if (frame_duration < m_frame_duration)
      {
        SDL_Delay (m_frame_duration - frame_duration);
      }
  }

  // If the game loop was broken the window should be close, so we return false
  return false;
}
} // namespace SDL
