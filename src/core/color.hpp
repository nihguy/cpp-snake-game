#ifndef CPP_SNAKE_GAME_CORE_COLOR_HPP
#define CPP_SNAKE_GAME_CORE_COLOR_HPP

namespace Capstone
{

typedef unsigned char Uint8;
typedef unsigned int Uint32;


/**
 * This defines a color that can be used by SDL functions
 *
 * This class was strongly inspired by SFML's Color. If you'd like to check
 * the original code, please take a look at:
 *
 * https://github.com/SFML/SFML/blob/master/include/SFML/Graphics/Color.hpp
 * https://github.com/SFML/SFML/blob/master/src/SFML/Graphics/Color.cpp
 */
class Color
{
 public:

  /**
   * Default constructor
   *
   * This defines the current color as black
   */
  Color();

  /**
   * Parameterized constructor
   *
   * It allows the current class to define each channel with values between
   * 0 and 255
   *
   * @param red    Red color channel
   * @param green  Green color channel
   * @param blue   Blue color channel
   * @param alpha  Alpha color channel
   */
  Color(int red, int green, int blue, int alpha = 255);

  /**
   * It allows the current class to define the color as hexadecimal
   *
   * Instead of setting each channel color, this constructor uses a single
   * value as argument, defining the four channels as hexadecimal as follows:
   *
   *  auto dodge_blue = Color(0x0084ffff);
   *
   * @param color  The color as hexadecimal value
   */
  explicit Color(Uint32 color);

  /**
   * The most common colors
   *
   * They are defined as static variables making possible to use Color::White,
   * as a shortcut to Color(255, 255, 255), for example.
   */
  static const Color Black;
  static const Color White;
  static const Color Red;
  static const Color Green;
  static const Color Blue;
  static const Color Yellow;
  static const Color Magenta;
  static const Color Cyan;
  static const Color Transparent;

 public:

  /**
   * This defines all color channels as public
   *
   * All values can be assigned with values between 0 and 255
   */
  Uint8 r; // red
  Uint8 g; // green
  Uint8 b; // blue
  Uint8 a; // alpha (opacity)
};

/**
 * Overload of the == operator
 *
 * This operator compares two colors and check if they are equal.
 *
 * @param left   Left operand
 * @param right  Right operand
 * @returns boolean  Returns true if colors are equal, false if they are different
 */
bool operator ==(const Color &left, const Color &right);

/**
 * Overload of the != operator
 *
 * This operator compares two colors and check if they are different.
 *
 * Returns true if colors are different, false if they are equal
 *
 * @param left   Left operand
 * @param right  Right operand
 * @returns boolean
 */
bool operator !=(const Color &left, const Color &right);

/**
 * Overload of the binary + operator
 *
 * This operator returns the component-wise sum of two colors.
 * Components that exceed 255 are clamped to 255.
 *
 * it allows lighten colors like:
 *
 *   auto new_color = Color::Red + Color(50, 50, 50) // Color(255, 50, 50, 255);
 *
 * @param left  Left operand
 * @param right Right operand
 *
 * @returns Color
 */
Color operator +(const Color &left, const Color &right);

/**
 * Overload of the binary - operator
 *
 * This operator returns the component-wise subtraction of two colors.
 * Components that exceed 255 are clamped to 255.
 *
 * It allows darken colors like:
 *
 *   auto new_color = Color::Red - Color(50, 50, 50, 0) // Color(205, 0, 0, 255);
 *
 * @param left  Left operand
 * @param right Right operand
 *
 * @returns Color
 */
Color operator -(const Color &left, const Color &right);

/**
 * Overload of the binary * operator
 *
 * This operator returns the component-wise multiplication of two colors.
 * Components that exceed 255 are clamped to 255.
 *
 * It creates darken colors like:
 *
 *   auto new_color = Color::Red * Color(50, 50, 50) // Color(50, 0, 0, 255);
 *
 * @param left  Left operand
 * @param right Right operand
 *
 * @returns Color
 */
Color operator *(const Color &left, const Color &right);

/**
 * Overload of the binary += operator
 *
 * This operator computes the component-wise sum of two colors,
 * and assigns the result to the left operand.
 * Components that exceed 255 are clamped to 255.
 *
 * It creates lighten colors like:
 *
 *   auto current_color = Color::Red;
 *   current_color += Color(50, 50, 50) // Color(255, 50, 50, 255);
 *
 * @param left  Left operand
 * @param right Right operand
 *
 * @returns Color
 */
Color& operator +=(Color &left, const Color &right);

/**
 * Overload of the binary -= operator
 *
 * This operator computes the component-wise subtract of two colors,
 * and assigns the result to the left operand.
 * Components that exceed 255 are clamped to 255.
 *
 * It creates darken colors like:
 *
 *   auto current_color = Color::Red;
 *   current_color -= Color(50, 50, 50) // Color(205, 0, 0, 255);
 *
 * @param left  Left operand
 * @param right Right operand
 *
 * @returns Color
 */
Color& operator -=(Color &left, const Color &right);

/**
 * Overload of the binary *= operator
 *
 * This operator computes the component-wise multiplication of two colors,
 * and assigns the result to the left operand.
 * Components that exceed 255 are clamped to 255.
 *
 * It creates darken colors like:
 *
 *   auto current_color = Color::Red;
 *   current_color *= Color(50, 50, 50) // Color(50, 0, 0, 255);
 *
 * @param left  Left operand
 * @param right Right operand
 *
 * @returns Color
 */
Color& operator *=(Color &left, const Color &right);

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_COLOR_HPP
