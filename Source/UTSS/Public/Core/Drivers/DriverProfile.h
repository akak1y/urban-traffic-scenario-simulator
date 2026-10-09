#pragma once

namespace utss
{
    /**
     * Behavioral profile of the human driving a vehicle. Sampled randomly
     * per spawn (biased by vehicle class in later milestones) so that an
     * identical fleet does not behave identically.
     *
     * Most fields are normalized to [0, 1]; factors are centered on 1.0.
     */
    struct DriverProfile
    {
        float aggression = 0.5f;
        float patience = 0.5f;
        float compliance = 0.8f;
        float distractibility = 0.1f;
        float courtesy = 0.5f;

        /** Multiplier on posted/desired speed. */
        float desiredSpeedFactor = 1.0f;

        /** Multiplier on safe headway distance. */
        float headwayFactor = 1.0f;

        /** Willingness to initiate lane changes, [0, 1]. */
        float laneChangeEagerness = 0.5f;

        /** Perception/reaction delay in seconds before responding to a
         *  newly visible leader, obstacle, pedestrian, or emergency vehicle. */
        float reactionDelay = 0.6f;
    };
}
