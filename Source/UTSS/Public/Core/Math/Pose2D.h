#pragma once

#include "Core/Math/Vec2.h"

namespace utss
{
    /**
     * Planar pose: position plus heading angle in radians.
     * Theta is measured counter-clockwise from the +X axis.
     */
    struct Pose2D
    {
        Vec2 position;
        float theta = 0.0f;
    };
}
