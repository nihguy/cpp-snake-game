template<typename T>
Capstone::Vector2<T>::Vector2 ():
  x(0),
  y(0)
{

}

template<typename T>
Capstone::Vector2<T>::Vector2 (T equal):
    x(equal),
    y(equal)
{

}

template<typename T>
Capstone::Vector2<T>::Vector2 (T X, T Y):
  x(X),
  y(Y)
{

}

template<typename T>
template<typename U>
Capstone::Vector2<T>::Vector2 (const Capstone::Vector2<U>& vector):
  x(static_cast<T>(vector.x)),
  y(static_cast<T>(vector.y))
{

}

template<typename T>
Capstone::Vector2<T> operator -(const Capstone::Vector2<T> &right) {
  return Capstone::Vector2<T>(-right.x, -right.y);
}

template<typename T>
Capstone::Vector2<T>& operator +=(Capstone::Vector2<T> &left, const Capstone::Vector2<T> &right) {
  left.x += right.x;
  left.y += right.y;

  return left;
}

template<typename T>
Capstone::Vector2<T>& operator -=(Capstone::Vector2<T> &left, const Capstone::Vector2<T> &right) {
  left.x -= right.x;
  left.y -= right.y;

  return left;
}

template<typename T>
Capstone::Vector2<T> operator +(const Capstone::Vector2<T> &left, const Capstone::Vector2<T> &right) {
  return Capstone::Vector2<T>(left.x + right.x, left.y + right.y);
}

template<typename T>
Capstone::Vector2<T> operator -(const Capstone::Vector2<T> &left, const Capstone::Vector2<T> &right) {
  return Capstone::Vector2<T>(left.x - right.x, left.x - right.x);
}

template<typename T>
Capstone::Vector2<T> operator *(const Capstone::Vector2<T> &left, T right) {
  return Capstone::Vector2<T>(left.x * right, left.y * right);
}

template<typename T>
Capstone::Vector2<T> operator *(T left, const Capstone::Vector2<T> &right) {
  return Capstone::Vector2<T>(right.x * left, right.y * left);
}

template<typename T>
Capstone::Vector2<T>& operator *=(Capstone::Vector2<T> &left, T right) {
  left.x *= right;
  left.y *= right;

  return left;
}

template<typename T>
Capstone::Vector2<T> operator /(const Capstone::Vector2<T> &left, T right) {
  return Vector2<T>(left.x / right, left.y / right);
}

template<typename T>
Capstone::Vector2<T>& operator /=(Capstone::Vector2<T> &left, T right) {
  left.x /= right.x;
  left.y /= right.y;

  return left;
}

template <typename T, typename U>
bool operator ==(const Capstone::Vector2<T>& left, const Capstone::Vector2<U>& right)
{
  return (left.x == right.x) && (left.y == right.y);
}

template <typename T, typename U>
bool operator !=(const Capstone::Vector2<T>& left, const Capstone::Vector2<U>& right)
{
  return !(left == right);
}