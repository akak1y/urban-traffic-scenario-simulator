# UrbanTrafficScenarioSimulator

UrbanTrafficScenarioSimulator (internal module name: `UTSS`, C++ namespace: `utss`) is a C++/Unreal traffic simulation project for modeling urban road scenarios, congestion, incidents, intersections, public transport, pedestrians, bicycles, emergency vehicles, and driver behavior.

The project is built around a plain C++ simulation core, with Unreal Engine used for visualization, debugging, interactive demos, and level editing.

## Goals

- Simulate realistic urban traffic congestion.
- Support thousands of agents over time.
- Model cars, trucks, buses, bicycles, pedestrians, emergency vehicles, and police.
- Support road scenarios: accidents, roadworks, broken traffic lights, yard turns, bus stops, parking.
- Support vehicle classes and randomized driver behavior profiles.
- Model visibility restrictions caused by placed occluders such as fences, buildings, parked vehicles, and construction barriers — a vehicle must slow down because it cannot see what is ahead, not because the road is magically marked as dangerous.
- Keep the simulation core independent from the rendering engine.
- Provide deterministic replay and scenario testing.

## Technology

- Language: C++
- Engine: Unreal Engine 5.x (developed against 5.8)
- Core namespace: `utss`
- License: MIT

## CI

[![CI](https://github.com/akak1y/urban-traffic-scenario-simulator/actions/workflows/ci.yml/badge.svg)](https://github.com/akak1y/urban-traffic-scenario-simulator/actions/workflows/ci.yml)

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE).
