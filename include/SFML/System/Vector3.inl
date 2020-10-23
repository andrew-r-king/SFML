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

#include <SFML/System/Vector3.hpp>

namespace sf
{
////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector3<T>::Vector3(const T inX, const T inY, const T inZ) :
	x(inX),
	y(inY),
	z(inZ)
{
}


////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
constexpr Vector3<T>::Vector3(const Vector3<U>& inVector) :
	x(static_cast<T>(inVector.x)),
	y(static_cast<T>(inVector.y)),
	z(static_cast<T>(inVector.z))
{
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector3<T> operator -(const Vector3<T>& right)
{
	return Vector3<T>(-static_cast<T>(right.x), -static_cast<T>(right.y), -static_cast<T>(right.z));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T>& operator+=(Vector3<T>& left, const Vector3<U>& right)
{
	left.x += static_cast<T>(right.x);
	left.y += static_cast<T>(right.y);
	left.z += static_cast<T>(right.z);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T>& operator-=(Vector3<T>& left, const Vector3<U>& right)
{
	left.x -= static_cast<T>(right.x);
	left.y -= static_cast<T>(right.y);
	left.z -= static_cast<T>(right.z);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T> operator+(const Vector3<T>& left, const Vector3<U>& right)
{
	return Vector3<T>(left.x + static_cast<T>(right.x), left.y + static_cast<T>(right.y), left.z + static_cast<T>(right.z));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T> operator-(const Vector3<T>& left, const Vector3<U>& right)
{
	return Vector3<T>(left.x - static_cast<T>(right.x), left.y - static_cast<T>(right.y), left.z - static_cast<T>(right.z));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T> operator*(const Vector3<T>& left, U right)
{
	return Vector3<T>(left.x * static_cast<T>(right), left.y * static_cast<T>(right), left.z * static_cast<T>(right));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T> operator*(U left, const Vector3<T>& right)
{
	return Vector3<T>(right.x * static_cast<T>(left), right.y * static_cast<T>(left), right.z * static_cast<T>(left));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T>& operator*=(Vector3<T>& left, U right)
{
	left.x *= static_cast<T>(right);
	left.y *= static_cast<T>(right);
	left.z *= static_cast<T>(right);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T> operator/(const Vector3<T>& left, U right)
{
	return Vector3<T>(left.x / static_cast<T>(right), left.y / static_cast<T>(right), left.z / static_cast<T>(right));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr Vector3<T>& operator/=(Vector3<T>& left, U right)
{
	left.x /= static_cast<T>(right);
	left.y /= static_cast<T>(right);
	left.z /= static_cast<T>(right);

	return left;
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr bool operator==(const Vector3<T>& left, const Vector3<U>& right)
{
	return (left.x == static_cast<T>(right.x)) && (left.y == static_cast<T>(right.y)) && (left.z == static_cast<T>(right.z));
}


////////////////////////////////////////////////////////////
template <typename T, typename U>
constexpr bool operator!=(const Vector3<T>& left, const Vector3<U>& right)
{
	return (left.x != static_cast<T>(right.x)) || (left.y != static_cast<T>(right.y)) || (left.z != static_cast<T>(right.z));
}
}