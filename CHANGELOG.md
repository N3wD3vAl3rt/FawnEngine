# Fawn Engine Changelog

---

## v0.8.1

### Added
- Game abstraction layer
- Version system
- Build information system
- Window title displays engine version

### Improved
- Engine architecture
- Separation between Engine and Game

### Fixed
- N/A

## v0.8.2

### Added
- Time subsystem
- High-resolution timing using `std::chrono::steady_clock`
- Engine-wide `deltaTime`
- Total engine runtime tracking

### Changed
- Update pipeline now passes `deltaTime` from Engine to all entities.
- Player movement is now frame-rate independent.
- Player friction is frame-rate independent.

### Improved
- Engine timing consistency.
- Movement behaves consistently across different frame rates.