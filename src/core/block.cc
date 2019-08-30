
#include "block.hpp"

namespace Capstone
{

Block::Block ():
  iAllocation::Allocation{{ 0 }, { 0 }}
{

}

Block::Block (iVector2 size, iVector2 offset):
  iAllocation::Allocation{ size, offset }
{

}

void Block::update (std::size_t delta_time)
{

}

void Block::render (Renderer& renderer)
{
  // Defines the color and display the current GameObject into the screen
  renderer.fill_color (color);
  renderer.fill(*this);
}

void Block::prepare (Renderer& renderer)
{
  size = iVector2(
    renderer.get_screen ().x / renderer.get_grid ().x,
    renderer.get_screen ().y / renderer.get_grid ().y
  );
}

} // namespace Capstone
