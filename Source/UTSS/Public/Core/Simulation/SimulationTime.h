#pragma once

#include <cstdint>

namespace utss
{
    /**
     * Tracks deterministic simulation time using a fixed timestep.
     *
     * The core advances in constant increments (fixedDeltaTime) so that
     * results are reproducible regardless of the host frame rate. Real
     * elapsed time is fed in via ConsumeSteps, which accumulates leftover
     * fraction between steps.
     */
    struct SimulationTime
    {
        double currentTime = 0.0;
        std::int64_t stepCount = 0;

        /** Leftover real time not yet converted into fixed steps. */
        float accumulator = 0.0f;

        /**
         * Adds realDeltaSeconds to the accumulator and consumes as many
         * whole fixed steps as fit. Advances currentTime and stepCount
         * accordingly and returns how many steps the caller must run.
         *
         * @param realDeltaSeconds Wall-clock delta since last call (>= 0).
         * @param fixedDeltaTime   Fixed simulation step size in seconds (> 0).
         * @return Number of fixed steps to execute this tick (may be 0).
         */
        int ConsumeSteps(float realDeltaSeconds, float fixedDeltaTime);
    };
}
