#pragma once

namespace utss
{
    /**
     * Static physical characteristics of a vehicle class.
     * Units: meters, m/s, m/s^2, radians. Defaults describe a typical sedan.
     */
    struct VehicleParams
    {
        float length = 4.5f;
        float width = 1.8f;
        float height = 1.5f;

        float maxSpeed = 50.0f;
        float comfortableAccel = 2.0f;
        float comfortableDecel = 4.0f;
        float emergencyDecel = 8.0f;

        float minTurningRadius = 5.5f;
        float maxSteeringAngle = 0.6f;

        /** Relative mass factor used later for braking/turning adjustments. */
        float massFactor = 1.0f;
    };
}
