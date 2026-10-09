#pragma once

#include "Core/Math/Pose2D.h"

namespace utss
{
    /**
     * Per-vehicle dynamic state that changes every simulation step.
     * Kept compact and trivially copyable for cache-friendly iteration.
     */
    struct VehicleState
    {
        Pose2D pose;

        /** Scalar speed along the heading, m/s. Always >= 0 in this model. */
        float speed = 0.0f;

        /** Last applied longitudinal acceleration, m/s^2 (negative = braking). */
        float acceleration = 0.0f;

        /** Current steering angle, radians. */
        float steeringAngle = 0.0f;

        /** Current yaw rate, rad/s. */
        float yawRate = 0.0f;
    };
}
