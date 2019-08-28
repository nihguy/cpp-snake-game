
#ifndef CPP_SNAKE_GAME_STATE_PLAY_STATE_HPP
#define CPP_SNAKE_GAME_STATE_PLAY_STATE_HPP

#include <memory>

#include "../core/game_state.hpp"
#include "../core/controller.hpp"
#include "../core/block.hpp"
#include "../actor/snake.hpp"
#include "../core/random_position.hpp"

namespace Capstone
{

class MainState: public GameState
{
 public:
  void update (std::size_t delta_time) override;
  void render (Renderer& renderer) override;
  void prepare (Renderer& renderer) override;
  void handle_input (const KeyPressed &key) override;

 protected:
  std::unique_ptr<Block> m_food;
  std::unique_ptr<Snake> m_snake;

  RandomPosition m_random;
};

} // namespace Capstone

#endif //CPP_SNAKE_GAME_STATE_PLAY_STATE_HPP