
#ifndef CPP_SNAKE_GAME_SDL_GAME_LOOP_HPP
#define CPP_SNAKE_GAME_SDL_GAME_LOOP_HPP

#include "../core/game_loop.hpp"

namespace SDL
{

/**
 *
 */
class GameLoop: public Capstone::GameLoop {
 public:
  GameLoop(std::size_t target_frame_duration);
  ~GameLoop () = default;

  bool execute (Capstone::Game& game, Capstone::Renderer &renderer, Capstone::Controller &controller) const override;

 protected:
  std::size_t m_frame_duration;
};
} // namespace SDL

#endif // CPP_SNAKE_GAME_SDL_GAME_LOOP_HPP
