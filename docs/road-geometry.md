# Road Geometry and Scenario Model

UrbanTrafficScenarioSimulator is intended to model non-standard urban road scenarios where geometry, visibility, public transport, incidents, and weather create congestion.

## Core Idea

A road is represented as a lane graph. Each lane is not a simple constant-width ribbon. Each lane has a profile along its length:

- centerline geometry;
- arc-length coordinate `s`;
- width as a function of `s`;
- lateral offset as a function of `s`;
- curvature;
- local speed limit;
- available sight distance;
- surface type;
- friction scale;
- allowed vehicle classes;
- connections to other lanes.

## Lane Types

Planned lane types: Driving, TurnLeft, TurnRight, Merge, Diverge, Exit, BusLane, BusBay, BusStopApproach, BusStopExit, Parking, YardAccess, BikeLane, Shoulder, WorkZone, Closed.

## Connection Types

Planned connection types: Straight, LeftTurn, RightTurn, Merge, Diverge, TaperIn, TaperOut, BayEntry, BayExit, YardAccess, EmergencyOnly.

## Occluder-Based Visibility

Visibility is not assumed to be a static property of a lane. It must be derived from scene occluders placed by the user.

A vehicle may slow down before a curve not only because of curvature, but because an object such as a fence, building, parked van, bus, construction barrier, or vegetation blocks the driver's line of sight. The user places the obstacle; the simulator computes the consequence.

### Occluder Concept

An occluder is a scenario object that can block motion, visibility, or both.

Examples:

- A side fence may block visibility but not motion.
- A construction barrier may block both motion and visibility.
- A bus may block motion and visibility.
- A low curb may block neither.
- Bushes may partially block visibility.

Initial simplified model:

```text
blocksMotion: bool
blocksVisibility: bool
height: float
polygon: 2D footprint
```

Future extensions: visibility strength / opacity; height-based line-of-sight blocking; driver eye height; weather/night visibility; glare; fog; dynamic occluders.

### Visibility Profile

For each lane the simulator computes a visibility profile:

```text
s -> sightDistance
```

Where `s` is arc-length position along the lane and `sightDistance` is the maximum distance the driver can see ahead from that position. This profile is precomputed for static occluders. For dynamic occluders, affected lane segments are recomputed locally.

### Line of Sight

A point ahead on the road is visible if the line segment from the driver eye point to that point does not intersect any visibility-blocking occluder.

Initial 2D approximation: the driver eye point is projected onto the lane; visibility rays are cast forward along the lane and/or toward future lane points; the nearest occluding intersection defines available sight distance. A more accurate later model can use multiple rays (centerline, left edge, right edge, adjacent lanes, forward field-of-view fan).

### Speed From Visibility

Available sight distance limits safe speed. Required stopping sight distance:

```text
SSD = v * reactionTime + v^2 / (2 * comfortableDecel)
```

Given available sight distance `S`, safe speed is:

```text
v = -b * tr + sqrt((b * tr)^2 + 2 * b * S)
```

where `b` is comfortable deceleration, `tr` is driver reaction time, `S` is available sight distance.

The final target speed is:

```text
targetSpeed = min(
    postedSpeedLimit,
    curveSpeed,
    sightDistanceSpeed,
    weatherSpeed,
    vehicleClassSpeed,
    driverDesiredSpeed,
    visibleObstacleSpeed
)
```

For blind turns caused by fences or buildings, `sightDistanceSpeed` may dominate even if the curve itself is gentle. This is the intended behavior: the car slows because it cannot see, not because the road is marked dangerous.

### Perception Delay

A vehicle must not instantly react to objects that were previously hidden. When a new leader, obstacle, pedestrian, bus, incident, or emergency vehicle becomes visible:

1. the perception system marks it as newly seen;
2. a driver reaction timer starts;
3. only after the reaction delay does the vehicle fully respond;
4. if distance is too short, emergency braking is used.

This creates realistic hard-braking waves and congestion behind blind corners.

### Scenario Authoring

Scenarios support explicit occluders:

```yaml
occluders:
  - id: fence_after_turn
    type: fence
    height: 2.5
    blocks_motion: false
    blocks_visibility: true
    polygon:
      - [95, 18]
      - [120, 35]
      - [123, 32]
      - [98, 15]
```

Validation should warn when:

- sight distance is too short for the posted speed limit;
- a bus bay is placed immediately after a low-visibility curve;
- an occluder blocks visibility of a conflict point without adequate warning;
- a lane drop or merge is hidden behind an occluder;
- a large vehicle cannot safely navigate a visibility-limited turn.

## Variable Width and Lane Drops

Roads may narrow or expand. Initial representation: each lane has `width(s)`; lanes can taper in/out; connections represent lane drops and lane additions. Future representation: road cross-sections with multiple lane slots, left/right boundary geometry, dynamic construction zones, temporary lane shifts.

## Bus Bays

A bus bay is a special lane branch used by buses to stop without fully blocking the main lane. Important properties: bay entry/exit taper, bay width, bus stop position, dwell time, passenger boarding/alighting, whether the bay is blocked by illegal parking, whether other vehicles can pass the bus, and whether the bay is immediately after a low-visibility curve. A bus bay after a blind turn is a first-class scenario because drivers may discover a stopped bus too late, causing hard braking and queue formation.
