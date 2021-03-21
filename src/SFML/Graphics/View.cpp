////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2021 Laurent Gomila (laurent@sfml-dev.org)
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
#include <SFML/Graphics/View.hpp>
#include <cmath>


namespace sf
{
////////////////////////////////////////////////////////////
View::View()
{
    reset(FloatRect(0, 0, 1000, 1000));
}


////////////////////////////////////////////////////////////
View::View(const FloatRect& rectangle)
{
    reset(rectangle);
}


////////////////////////////////////////////////////////////
View::View(const Vector2f& center, const Vector2f& size) :
    m_center(center),
    m_size(size)
{

}

////////////////////////////////////////////////////////////
void View::setRotation(const float angle)
{
    m_rotation = static_cast<float>(fmod(angle, 360));
    if (m_rotation < 0)
        m_rotation += 360.f;

    m_transformUpdated    = false;
    m_invTransformUpdated = false;
}

////////////////////////////////////////////////////////////
void View::rotate(const float angle)
{
    setRotation(m_rotation + angle);
}

} // namespace sf
