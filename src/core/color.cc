#include "color.hpp"

namespace Capstone
{

const Color Color::Black (0, 0, 0);
const Color Color::White (255, 255, 255);
const Color Color::Red (255, 0, 0);
const Color Color::Green (0, 255, 0);
const Color Color::Blue (0, 0, 255);
const Color Color::Yellow (255, 255, 0);
const Color Color::Magenta (255, 0, 255);
const Color Color::Cyan (0, 255, 255);
const Color Color::Transparent (0, 0, 0, 0);

// Default constructor
// This Defines blacks as current color
Color::Color ():
  r (0),
  g (0),
  b (0),
  a (255)
{

}

// Parametrized constructor
// This defines each color channel
Color::Color (int red, int green, int blue, int alpha):
  r (static_cast<Uint8>(std::min(std::max(red, 0),255))),
  g (static_cast<Uint8>(std::min(std::max(green, 0),255))),
  b (static_cast<Uint8>(std::min(std::max(blue, 0),255))),
  a (static_cast<Uint8>(std::min(std::max(alpha, 0),255)))
{

}

// This defines the current color as hexadecimal
Color::Color (Uint32 color):
  r (static_cast<Uint8>((color & 0xff000000) >> 24)),
  g (static_cast<Uint8>((color & 0x00ff0000) >> 16)),
  b (static_cast<Uint8>((color & 0x0000ff00) >> 8)),
  a (static_cast<Uint8>((color & 0x000000ff) >> 0))
{

}

// Overload of the binary == operator
bool operator== (const Color& left, const Color& right)
{
  return (left.r == right.r) &&
         (left.g == right.g) &&
         (left.b == right.b) &&
         (left.a == right.a);
}

// Overload of the binary != operator
bool operator!= (const Color& left, const Color& right)
{
  return !(left == right);
}

// Overload of the binary + operator
Color operator+ (const Color& left, const Color& right)
{
  return Color(Uint8(std::min(int(left.r) + right.r, 255)),
               Uint8(std::min(int(left.g) + right.g, 255)),
               Uint8(std::min(int(left.b) + right.b, 255)),
               Uint8(std::min(int(left.a) + right.a, 255)));
}

// Overloads of the binary - operator
Color operator- (const Color& left, const Color& right)
{
  return Color(Uint8(std::max(int(left.r) - right.r, 0)),
               Uint8(std::max(int(left.g) - right.g, 0)),
               Uint8(std::max(int(left.b) - right.b, 0)),
               Uint8(std::max(int(left.a) - right.a, 0)));
}

// Overloads of the binary * operator
Color operator* (const Color& left, const Color& right)
{
  return Color(Uint8(int(left.r) * right.r / 255),
               Uint8(int(left.g) * right.g / 255),
               Uint8(int(left.b) * right.b / 255),
               Uint8(int(left.a) * right.a / 255));
}

// Overloads of the binary += operator
Color& operator+= (Color& left, const Color& right)
{
  return left = left + right;
}

// Overloads of the binary -= operator
Color& operator-= (Color& left, const Color& right)
{
  return left = left - right;
}

// Overloads of the binary *= operator
Color& operator*= (Color& left, const Color& right)
{
  return left = left * right;
}

} // namespace Capstone