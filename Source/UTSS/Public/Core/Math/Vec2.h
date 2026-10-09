#pragma once

namespace utss
{
    /**
     * Minimal 2D vector used by the simulation core.
     * Deliberately free of Unreal types so the core stays portable.
     */
    struct Vec2
    {
        float x = 0.0f;
        float y = 0.0f;

        Vec2 operator+(const Vec2& other) const noexcept
        {
            return { x + other.x, y + other.y };
        }

        Vec2 operator-(const Vec2& other) const noexcept
        {
            return { x - other.x, y - other.y };
        }

        Vec2 operator*(float scalar) const noexcept
        {
            return { x * scalar, y * scalar };
        }
    };

    /** Euclidean length of the vector. Defined in Vec2.cpp. */
    float Length(const Vec2& v) noexcept;

    /**
     * Returns a unit-length vector pointing in the same direction.
     * Returns a zero vector when the input length is below epsilon,
     * so callers never divide by zero. Defined in Vec2.cpp.
     */
    Vec2 Normalize(const Vec2& v) noexcept;
}
