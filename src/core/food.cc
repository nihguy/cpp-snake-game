
#include "food.hpp"
#include "random_position.hpp"

namespace Capstone
{

void Food::render (Renderer& renderer)
{
  m_food->render (renderer);
}

// This replaces the food offset using a thread that returns
// a non-filled "game space"
void Food::replace()
{
  // This is executed in another thread
  auto offset = std::async(&Food::replace_food, this, m_target, m_random);
  offset.wait();

  // The offset is not colliding with the head and body Snake
  m_food->offset = offset.get();
}

// This prepares the Food to be rendered
void Food::prepare (Renderer& renderer)
{
  m_random = std::make_shared<RandomPosition> (renderer.get_grid ());

  // This creates the Block and prepare it
  m_food = std::move(std::make_shared<Block>());
  m_food->prepare (renderer);

  // This set the color
  m_food->color = Color(0xFFCC00FF);

  iVector2 player_position = {renderer.get_grid ().x - 1, renderer.get_grid ().y - 1};

  // This ensures the Food and the Snake will not placed in same offset
  // on the first time
  while(true)
  {
    auto offset = m_random->get();

    if (player_position != offset)
    {
      m_food->offset = offset;
      break;
    }
  }

  // This starts the `check_collision` in another thread
  m_threads.emplace_back(std::thread(&Food::shared_check_collision, this));
}

// This dispatch a SnakeStatus::kEating to Snake when the food and the actor
// is colliding
void Food::shared_check_collision ()
{
  while(m_target != nullptr)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::unique_lock<std::mutex> lock(m_mutex);

    if (m_target->get_status () != SnakeStatus::kEating)
    {
      if (m_target->check_collision (*m_food))
      {
        m_target->set_status(get_status ());
      }
    }
  }
}

void Food::update (std::size_t delta_time)
{
  m_food->update (delta_time);
}

// This assign the game actor to be used on check_collision properly
void Food::set_target (std::shared_ptr<Snake> target)
{
  m_target = std::move(target);
}

// This defines the only SnakeStatus dispatched by class
const SnakeStatus Food::get_status () const
{
  return SnakeStatus::kEating;
}

// This ensures the food will not be placed in an already filled "grid space"
iVector2 Food::replace_food (const std::shared_ptr<Snake>& snake, std::shared_ptr<RandomPosition> random)
{
  while(true)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::unique_lock<std::mutex> lock(m_mutex);

    // This creates a new offset to replace the food
    auto new_offset = random->get();

    // It ensures the Snake's head is not occupying the same "grid space"
    // of the new proposed offset
    if (new_offset == iVector2(snake->offset))
    {
      continue;
    }

    // It ensures the Snake's body is not occupying the same "grid space"
    // of the new proposed offset
    for(const auto& item: snake->body)
    {
      if (new_offset == item.offset)
      {
        continue;
      }
    }

    return new_offset;
  }
}

} // namespace Capstone
