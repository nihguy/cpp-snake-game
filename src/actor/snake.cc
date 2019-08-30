
#include "snake.hpp"

namespace Capstone {

// Default constructor
Snake::Snake ():
  m_status(SnakeStatus::kWalking),
  m_direction(Direction::kUp),
  m_speed(0.2f),
  m_growing{false}
{

}

// This updates the Snake's behavior
void Snake::update (std::size_t delta_time)
{
  if (m_status == SnakeStatus::kColliding)
  {
    // It changes the head color when the Snake collides
    head_color = Color::Red;
    return;
  }

  // We first capture the head's cell before updating
  iVector2 prev_cell = iVector2(offset);
  update_head ();

  // After update, we capture the head's cell again
  iVector2 current_cell = iVector2(offset);

  // Update all of the body vector items if the snake head has moved to a new cell
  if (current_cell != prev_cell)
  {
    // Add previous head location to vector if its growing (eating food)
    if (m_growing){
      push(std::move(prev_cell));
      m_growing = false;
    }

    // It ensures the body will follow the Snake's head
    for(auto &item: body) {
      auto current_cell = item.offset;
      item.offset = prev_cell;
      prev_cell = current_cell;
    }
  }
}

// This render the Snake's head and body, properly
void Snake::render (Renderer& renderer)
{
  // Render snake's body
  renderer.fill_color (body_color);
  for (const Block& point: body)
  {
    renderer.fill(point);
  }

  // Render snake's head
  renderer.fill_color (head_color);
  renderer.fill(get_allocation_as<int> ());
}

// This prepares the Snake to be rendered
void Snake::prepare (Renderer& renderer)
{
  // This ensures the Snake will "warp" correctly on the window edge
  m_grid = renderer.get_grid ();

  // This adjusts the size to the renderer grid
  size = fVector2(
    1.f * renderer.get_screen ().x / renderer.get_grid ().x,
    1.f * renderer.get_screen ().y / renderer.get_grid ().y
  );

  // The first offset is the bottom-left window corner
  offset = {
    m_grid.x - 1.f,
    m_grid.y - 1.f,
  };

  // It changes the Snake's head and body color
  body_color = Color::White;
  head_color = Color(0x7ACCFFFF);

  // This executes the collision check on another thread
  m_threads.emplace_back(std::thread(&Snake::shared_check_collision, this));
}

// This defines the own input handler
void Snake::handle_input (const KeyPressed & key)
{
  switch (key)
  {
    case KeyPressed::kUp:
      change_direction (Direction::kUp, Direction::kDown);
      break;
    case KeyPressed::kDown:
      change_direction (Direction::kDown, Direction::kUp);
      break;
    case KeyPressed::kLeft:
      change_direction (Direction::kLeft, Direction::kRight);
      break;
    case KeyPressed::kRight:
      change_direction (Direction::kRight, Direction::kLeft);
      break;
  }
}

// It allows the class to avoid change the position to the opposite direction
void Snake::change_direction (const Snake::Direction input, const Snake::Direction oposite)
{
  if (m_direction != oposite) m_direction = input;
}

// This updates the offset direction and speed
void Snake::update_head ()
{
  // Changes the head direction and accelerate it in a constant speed;
  switch(m_direction)
  {
    case Direction::kUp:
      offset.y -= m_speed;
      break;
    case Direction::kDown:
      offset.y += m_speed;
      break;
    case Direction::kLeft:
      offset.x -= m_speed;
      break;
    case Direction::kRight:
      offset.x += m_speed;
      break;
  }

  // Wraps the snake around to the beginning if going off the screen.
  offset.x = fmod(offset.x + m_grid.x, m_grid.x);
  offset.y = fmod(offset.y + m_grid.y, m_grid.y);
}

// It allows another GameThread to dispatch SnakeStatus when
// it collides with Snake
void Snake::set_status (SnakeStatus&& status)
{
  m_status = status;
}

// It adds the block to the Snake's body vector
void Snake::push (const iVector2&& offset)
{
  body.emplace_back (Block(iVector2(size), offset));
}

// This checks if the Snake collides with their body
void Snake::shared_check_collision ()
{
  while(true)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    std::unique_lock<std::mutex> lock(m_mutex);
    // Check if the snake has died
    for (const auto &item: body)
    {
      if (item.offset == iVector2(offset))
      {
        m_status = SnakeStatus::kColliding;
      }
    }
  }
}

const SnakeStatus Snake::get_status () const
{
  return m_status;
}

// This reset the Snake behavior
void Snake::reset ()
{
  body.clear ();
  m_speed = 0.2f;
  m_growing = false;
  offset = { m_grid.x - 1.f, m_grid.y - 1.f};
  head_color = Color(0x7ACCFFFF);
  m_status = SnakeStatus::kWalking;
  m_direction  = Direction::kUp;
}

// This alert the Snake it's growing
void Snake::growing ()
{
  m_growing = true;
  m_status = SnakeStatus::kWalking;
  m_speed += 0.01;
}

} // namespace Capstone