# Architecture

UrbanTrafficScenarioSimulator (Unreal module `UTSS`, C++ namespace `utss`) is split into two main layers:

1. Traffic Core
2. Unreal Engine presentation layer

## Traffic Core

The traffic core is plain C++ and must not depend on Unreal Engine.

It owns:

- simulation time;
- vehicle states and parameters;
- driver profiles;
- lane graph and road profiles;
- occluders and visibility profiles;
- perception state per agent;
- routes;
- traffic events and incidents;
- weather;
- metrics;
- deterministic RNG.

## Unreal Engine Layer

Unreal Engine is responsible for:

- rendering;
- camera;
- debug drawing (sight rays, occluders, perceived leaders, reaction timers);
- level setup;
- input;
- UI;
- synchronization from core state to actors or instanced meshes.

## Design Rules

- Do not put heavy simulation logic into `AActor`.
- Keep vehicle data in compact structs; avoid per-agent heap allocations in hot loops.
- Use lane-based spatial indexing (lane id + arc-length `s`) for leader lookup.
- Keep simulation deterministic with fixed timestep and seeded RNG.
- Separate longitudinal control, lateral control, perception, decision making, and collision.
- Keep `Core` code free of Unreal includes; Unreal-specific code lives outside the core boundary.
- Visibility is perception-based, not omniscient: an agent reacts only to what it can see.
- Occluders may block visibility without blocking motion (a side fence hides a bus but does not stop a car).

## Planned Core Modules

- `Math`
- `Simulation`
- `Vehicles`
- `Drivers`
- `RoadNetwork`
- `Routing`
- `Perception`
- `Visibility`
- `TrafficModels`
- `Weather`
- `Incidents`
- `Metrics`
- `Replay`
