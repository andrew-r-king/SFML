////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2020 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


#include <SFML/System/Vector2.hpp>

namespace sf
{
////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T>::Vector2(const T X, const T Y) :
	x(X),
	y(Y)
{
}


////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
constexpr Vector2<T>::Vector2(const Vector2<U>& vector) :
	x(static_cast<T>(vector.x)),
	y(static_cast<T>(vector.y))
{
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T> operator-(const Vector2<T>& right) noexcept
{
    return Vector2<T>(-right.x, -right.y);
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T>& operator+=(Vector2<T>& left, const Vector2<U>& right) noexcept
{
	left.x += static_cast<T>(right.x);
	left.y += static_cast<T>(right.y);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T>& operator-=(Vector2<T>& left, const Vector2<U>& right) noexcept
{
	left.x -= static_cast<T>(right.x);
	left.y -= static_cast<T>(right.y);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T> operator+(const Vector2<T>& left, const Vector2<U>& right) noexcept
{
	return Vector2<T>(left.x + static_cast<T>(right.x), left.y + static_cast<T>(right.y));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T>& operator+(Vector2<T>& left, const U right) noexcept
{
	left.x += static_cast<T>(right);
	left.y += static_cast<T>(right);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T> operator-(const Vector2<T>& left, const Vector2<U>& right) noexcept
{
	return Vector2<T>(left.x - static_cast<T>(right.x), left.y - static_cast<T>(right.y));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T>& operator-(Vector2<T>& left, const U right) noexcept
{
	left.x -= static_cast<T>(right);
	left.y -= static_cast<T>(right);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T> operator*(const Vector2<T>& left, U right) noexcept
{
	return Vector2<T>(left.x * static_cast<T>(right), left.y * static_cast<T>(right));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T> operator*(U left, const Vector2<T>& right) noexcept
{
	return Vector2<T>(right.x * static_cast<T>(left), right.y * static_cast<T>(left));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T>& operator*=(Vector2<T>& left, U right) noexcept
{
	left.x *= static_cast<T>(right);
	left.y *= static_cast<T>(right);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T> operator/(const Vector2<T>& left, U right) noexcept
{
	return Vector2<T>(left.x / static_cast<T>(right), left.y / static_cast<T>(right));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector2<T>& operator/=(Vector2<T>& left, U right) noexcept
{
	left.x /= static_cast<T>(right);
	left.y /= static_cast<T>(right);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr bool operator==(const Vector2<T>& left, const Vector2<U>& right) noexcept
{
	return (left.x == static_cast<T>(right.x)) && (left.y == static_cast<T>(right.y));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr bool operator!=(const Vector2<T>& left, const Vector2<U>& right) noexcept
{
	return (left.x != static_cast<T>(right.x)) || (left.y != static_cast<T>(right.y));
}

} // namespace sf