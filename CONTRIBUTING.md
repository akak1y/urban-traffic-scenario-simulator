# Contributing

Thanks for your interest in UrbanTrafficScenarioSimulator.

## General rules

- Use English for code, comments, commit messages, and documentation.
- Keep the simulation core independent from Unreal Engine.
- Do not put heavy traffic simulation logic into Unreal `AActor` classes.
- Prefer small, focused pull requests.
- Use Conventional Commits.

## Commit message format

```text
type(scope): short imperative summary
```

Examples:

- `feat(core): add vehicle state struct`
- `fix(ue): correct meter to unreal unit conversion`
- `docs: describe lane graph architecture`
- `ci: run core unit tests on pull requests`

## Code style

See `docs/coding-style.md`.

## Testing

When the core test infrastructure is ready, all changes to simulation logic should include tests. Important scenarios to test over time:

- vehicle braking distance;
- leader following;
- no collision during emergency braking;
- lane graph routing;
- occluder-based sight distance;
- blind turn with bus bay;
- yard turn congestion;
- weather friction effects;
- trailer kinematics;
- bus stop dwell behavior.
