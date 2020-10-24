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
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/MathConstants.hpp>
#include <cmath>


namespace sf
{
////////////////////////////////////////////////////////////
constexpr void View::setCenter(const float x, const float y) noexcept
{
    m_center.x = x;
    m_center.y = y;

    m_transformUpdated    = false;
    m_invTransformUpdated = false;
}


////////////////////////////////////////////////////////////
constexpr void View::setCenter(const Vector2f& center) noexcept
{
    setCenter(center.x, center.y);
}


////////////////////////////////////////////////////////////
constexpr void View::setSize(const float width, const float height) noexcept
{
    m_size.x = width;
    m_size.y = height;

    m_transformUpdated    = false;
    m_invTransformUpdated = false;
}


////////////////////////////////////////////////////////////
constexpr void View::setSize(const Vector2f& size) noexcept
{
    setSize(size.x, size.y);
}


////////////////////////////////////////////////////////////
constexpr void View::setViewport(const FloatRect& viewport)
{
    m_viewport = viewport;
}


////////////////////////////////////////////////////////////
constexpr void View::reset(const FloatRect& rectangle) noexcept
{
    m_center.x = rectangle.left + rectangle.width / 2.f;
    m_center.y = rectangle.top + rectangle.height / 2.f;
    m_size.x   = rectangle.width;
    m_size.y   = rectangle.height;
    m_rotation = 0;

    m_transformUpdated    = false;
    m_invTransformUpdated = false;
}


////////////////////////////////////////////////////////////
constexpr const Vector2f& View::getCenter() const noexcept
{
    return m_center;
}


////////////////////////////////////////////////////////////
constexpr const Vector2f& View::getSize() const noexcept
{
    return m_size;
}


////////////////////////////////////////////////////////////
constexpr float View::getRotation() const noexcept
{
    return m_rotation;
}


////////////////////////////////////////////////////////////
constexpr const FloatRect& View::getViewport() const noexcept
{
    return m_viewport;
}


////////////////////////////////////////////////////////////
constexpr void View::move(const float offsetX, const float offsetY) noexcept
{
    setCenter(m_center.x + offsetX, m_center.y + offsetY);
}


////////////////////////////////////////////////////////////
constexpr void View::move(const Vector2f& offset) noexcept
{
    setCenter(m_center + offset);
}


////////////////////////////////////////////////////////////
constexpr void View::zoom(const float factor) noexcept
{
    setSize(m_size.x * factor, m_size.y * factor);
}


////////////////////////////////////////////////////////////
constexpr const Transform& View::getTransform() const
{
    // Recompute the matrix if needed
    if (!m_transformUpdated)
    {
        // Rotation components
        float angle  = m_rotation * Math::pi / 180.f;
        float cosine = static_cast<float>(std::cos(angle));
        float sine   = static_cast<float>(std::sin(angle));
        float tx     = -m_center.x * cosine - m_center.y * sine + m_center.x;
        float ty     =  m_center.x * sine - m_center.y * cosine + m_center.y;

        // Projection components
        float a =  2.f / m_size.x;
        float b = -2.f / m_size.y;
        float c = -a * m_center.x;
        float d = -b * m_center.y;

        // Rebuild the projection matrix
        m_transform = Transform( a * cosine, a * sine,   a * tx + c,
                                -b * sine,   b * cosine, b * ty + d,
                                 0.f,        0.f,        1.f);
        m_transformUpdated = true;
    }

    return m_transform;
}


////////////////////////////////////////////////////////////
constexpr const Transform& View::getInverseTransform() const
{
    // Recompute the matrix if needed
    if (!m_invTransformUpdated)
    {
        m_inverseTransform = getTransform().getInverse();
        m_invTransformUpdated = true;
    }

    return m_inverseTransform;
}

} // namespace sf
