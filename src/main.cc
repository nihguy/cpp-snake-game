#include <iostream>
#include "core/controller.hpp"
#include "core/game.hpp"

#include "sdl/renderer.hpp"
#include "states/main_state.hpp"
#include "sdl/game_loop.hpp"
#include "sdl/controller.hpp"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  auto renderer = std::make_unique<SDL::Renderer>(Capstone::iVector2{ 640, 640 }, Capstone::iVector2{ 32, 32 });
  SDL::GameLoop game_loop { kMsPerFrame };
  SDL::Controller controller {};

  Capstone::Game game {std::move(renderer)};
  game.push_state (std::make_unique<Capstone::MainState>());

  return game.render (game_loop, controller);
}