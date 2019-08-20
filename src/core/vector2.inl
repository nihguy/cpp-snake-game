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

template <typename T>
bool operator ==(const Capstone::Vector2<T>& left, const Capstone::Vector2<T>& right)
{
  return (left.x == right.x) && (left.y == right.y);
}

template <typename T>
bool operator !=(const Capstone::Vector2<T>& left, const Capstone::Vector2<T>& right)
{
  return !(left == right);
}

