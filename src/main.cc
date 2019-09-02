#include <iostream>
#include "core/controller.hpp"
#include "core/game.hpp"

#include "sdl/renderer.hpp"
#include "sdl/game_loop.hpp"
#include "sdl/controller.hpp"
#include "sdl/game_font_builder.hpp"
#include "sdl/font_maker.hpp"
#include "states/splash_screen_state.hpp"

int main() {
  try
  {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

    auto renderer = std::make_unique<SDL::Renderer> (Capstone::iVector2{640, 640}, Capstone::iVector2{32, 32});
    auto game_font = std::make_unique<SDL::GameFontBuilder> ();

    SDL::GameLoop game_loop{kMsPerFrame};
    SDL::Controller controller{};

    Capstone::FontTheme font_theme_list[2] = { Capstone::FontTheme::kLight, Capstone::FontTheme::kDark };
    Capstone::FontSize font_size_list[4] = { Capstone::FontSize::kSmall, Capstone::FontSize::kMedium,  Capstone::FontSize::kLarge };

    for (const auto &theme : font_theme_list)
    {
      for (const auto &size : font_size_list)
      {
        game_font->set_font (theme, size, SDL::font_maker (theme, size));
      }
    }

    Capstone::Game game{std::move (renderer), std::move(game_font)};
    game.push_state (std::make_unique<Capstone::SplashScreenState> ());

    return game.render (game_loop, controller);
  }
  catch (std::exception& error)
  {
    std::cerr << error.what () << std::endl;
  }
}