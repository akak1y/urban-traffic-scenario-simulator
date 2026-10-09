#include "Core/Math/Vec2.h"

#include <cmath>

namespace utss
{
    namespace
    {
        constexpr float kEpsilon = 1e-6f;
    }

    float Length(const Vec2& v) noexcept
    {
        return std::sqrt(v.x * v.x + v.y * v.y);
    }

    Vec2 Normalize(const Vec2& v) noexcept
    {
        const float len = Length(v);
        if (len < kEpsilon)
        {
            return { 0.0f, 0.0f };
        }
        return { v.x / len, v.y / len };
    }
}
