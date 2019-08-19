#include <iostream>
#include "core/controller.hpp"
#include "core/game.hpp"
#include "core/renderer.hpp"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Capstone::Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Capstone::Controller controller;
  Capstone::Game game(kGridWidth, kGridHeight);
  game.run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!" << std::endl;
  std::cout << "Score: " << game.get_score() << std::endl;
  std::cout << "Size: " << game.get_size() << std::endl;
  return 0;
}