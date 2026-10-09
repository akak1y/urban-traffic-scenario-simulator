#include "Core/Simulation/SimulationTime.h"

namespace utss
{
    int SimulationTime::ConsumeSteps(float realDeltaSeconds, float fixedDeltaTime)
    {
        if (fixedDeltaTime <= 0.0f)
        {
            return 0;
        }

        if (realDeltaSeconds < 0.0f)
        {
            realDeltaSeconds = 0.0f;
        }

        accumulator += realDeltaSeconds;

        int steps = 0;
        const double stepSeconds = static_cast<double>(fixedDeltaTime);

        while (accumulator >= fixedDeltaTime)
        {
            accumulator -= fixedDeltaTime;
            currentTime += stepSeconds;
            ++stepCount;
            ++steps;
        }

        return steps;
    }
}
