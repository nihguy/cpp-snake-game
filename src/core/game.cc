
#include "game.hpp"

namespace Capstone
{

// Default constructor
Game::Game (std::unique_ptr<Renderer> renderer):
  m_renderer{std::move(renderer)},
  is_running{true}
{

}

// Destructor
Game::~Game ()
{
  // Deletes all
  while (!m_states.empty ())
  {
    pop_state ();
  }
}

// This creates the game loop
bool Game::render (GameLoop &game_loop, Controller &controller)
{
  // This allows each GameState to choose the next one. Moreover, it defines
  // the time between the frames and allow the GameState in focus to handle
  // their own inputs
  return game_loop.execute (*this, *m_renderer, controller);
}

void Game::push_state (std::unique_ptr<GameState> state)
{
  // It ensures the GameState will get access to the current game instance
  state->set_game_handler (*this);

  // This prepares the GameState in focus allowing it to get access
  // to the Renderer class
  state->prepare (*m_renderer);

  // It moves the smart pointer to the stack, keeping the order of execution
  m_states.push (std::move(state));
}

void Game::pop_state ()
{
  // It deletes the GameState in focus
  m_states.pop ();
}

void Game::replace_state (std::unique_ptr<GameState> state)
{
  // It deletes the GameState in focus
  if (!m_states.empty ())
  {
    pop_state ();
  }

  // It replace the GameState in focus by the assigned as argument
  push_state (std::move(state));
}

// This returns the GameState in focus
GameState *Game::peek_state ()
{
  // If the stack is empty, throws an error
  if (m_states.empty ())
  {
    throw std::range_error("Attempt to access invalid Game State on Capstone::Game class. Capstone::Game::pop_state removed the last one");
  }

  // It returns the current state
  return m_states.top ().get();
}

} // namespace Capstone