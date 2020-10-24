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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/System/Time.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
constexpr Time::Time() :
	m_microseconds(Sec(0))
{
}

////////////////////////////////////////////////////////////
constexpr Time::Time(const Int64 microseconds) :
	m_microseconds(Micro(microseconds))
{
}


////////////////////////////////////////////////////////////
constexpr float Time::asSeconds() const
{
	return static_cast<float>(asMicroseconds() / 1000000.f);
}


////////////////////////////////////////////////////////////
constexpr Int32 Time::asMilliseconds() const
{
	return static_cast<int>(asMicroseconds() / 1000);
}


////////////////////////////////////////////////////////////
constexpr Int64 Time::asMicroseconds() const
{
	return m_microseconds.time_since_epoch().count();
}



////////////////////////////////////////////////////////////
constexpr Time Time::seconds(const float amount)
{
    return Time(static_cast<Int64>(amount * 1000000));
}


////////////////////////////////////////////////////////////
constexpr Time Time::milliseconds(const Int32 amount)
{
    return Time(static_cast<Int64>(amount) * 1000);
}


////////////////////////////////////////////////////////////
constexpr Time Time::microseconds(const Int64 amount)
{
    return Time(amount);
}


////////////////////////////////////////////////////////////
constexpr bool operator ==(const Time& left, const Time& right)
{
    return left.asMicroseconds() == right.asMicroseconds();
}


////////////////////////////////////////////////////////////
constexpr bool operator !=(const Time& left, const Time& right)
{
    return left.asMicroseconds() != right.asMicroseconds();
}


////////////////////////////////////////////////////////////
constexpr bool operator <(const Time& left, const Time& right)
{
    return left.asMicroseconds() < right.asMicroseconds();
}


////////////////////////////////////////////////////////////
constexpr bool operator >(const Time& left, const Time& right)
{
    return left.asMicroseconds() > right.asMicroseconds();
}


////////////////////////////////////////////////////////////
constexpr bool operator <=(const Time& left, const Time& right)
{
    return left.asMicroseconds() <= right.asMicroseconds();
}


////////////////////////////////////////////////////////////
constexpr bool operator >=(const Time& left, const Time& right)
{
    return left.asMicroseconds() >= right.asMicroseconds();
}


////////////////////////////////////////////////////////////
constexpr Time operator -(const Time& right)
{
    return Time::microseconds(-right.asMicroseconds());
}


////////////////////////////////////////////////////////////
constexpr Time operator +(const Time& left, const Time& right)
{
    return Time::microseconds(left.asMicroseconds() + right.asMicroseconds());
}


////////////////////////////////////////////////////////////
constexpr Time& operator +=(Time& left, const Time& right)
{
    return left = left + right;
}


////////////////////////////////////////////////////////////
constexpr Time operator -(Time left, const Time& right)
{
    return Time::microseconds(left.asMicroseconds() - right.asMicroseconds());
}


////////////////////////////////////////////////////////////
constexpr Time& operator -=(Time& left, const Time& right)
{
    return left = left - right;
}


////////////////////////////////////////////////////////////
constexpr Time operator *(const Time& left, const float right)
{
    return Time::seconds(left.asSeconds() * right);
}


////////////////////////////////////////////////////////////
constexpr Time operator *(const Time& left, const Int64 right)
{
    return Time::microseconds(left.asMicroseconds() * right);
}


////////////////////////////////////////////////////////////
constexpr Time operator *(const float left, const Time& right)
{
    return right * left;
}


////////////////////////////////////////////////////////////
constexpr Time operator *(const Int64 left, const Time& right)
{
    return right * left;
}


////////////////////////////////////////////////////////////
constexpr Time& operator *=(Time& left, const float right)
{
    return left = left * right;
}


////////////////////////////////////////////////////////////
constexpr Time& operator *=(Time& left, const Int64 right)
{
    return left = left * right;
}


////////////////////////////////////////////////////////////
constexpr Time operator /(const Time& left, const float right)
{
    return Time::seconds(left.asSeconds() / right);
}


////////////////////////////////////////////////////////////
constexpr Time operator /(const Time& left, const Int64 right)
{
    return Time::microseconds(left.asMicroseconds() / right);
}


////////////////////////////////////////////////////////////
constexpr Time& operator /=(Time& left, const float right)
{
    return left = left / right;
}


////////////////////////////////////////////////////////////
constexpr Time& operator /=(Time& left, const Int64 right)
{
    return left = left / right;
}


////////////////////////////////////////////////////////////
constexpr float operator /(const Time& left, const Time& right)
{
    return left.asSeconds() / right.asSeconds();
}


////////////////////////////////////////////////////////////
constexpr Time operator %(const Time& left, const Time& right)
{
    return Time::microseconds(left.asMicroseconds() % right.asMicroseconds());
}


////////////////////////////////////////////////////////////
constexpr Time& operator %=(Time& left, const Time& right)
{
    return left = left % right;
}

} // namespace sf
