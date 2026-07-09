# Fawn Engine Design Specification

## Vision

Fawn Engine is a lightweight, modular game engine designed for creating high-performance 2D and 3D games while remaining readable, maintainable, and extensible.

---

## Philosophy

- Simplicity over complexity
- Modular architecture
- Stable APIs
- Incremental development
- Performance first
- Reusable engine systems
- Clear separation between Engine and Game

---

## Current Version

0.8.1


## Long-Term Goals

- Cross-platform support
- Scene management
- Resource manager
- Audio engine
- Animation system
- Physics
- Editor
- Plugin support
- Multiplayer foundation
- Scripting

## Core Systems

### Time

The Time subsystem provides a centralized source of timing information for the engine.

Responsibilities:

- Calculate deltaTime using a high-resolution timer.
- Track total engine runtime.
- Update once per frame.
- Provide timing information to all engine systems.

Current Consumers:

- Engine
- Game
- World
- EntityManager
- Entity
- Player
- Enemy

### Scene

The Scene subsystem defines a common interface for all engine scenes.

Current implementation:

- World

Future implementations:

- Main Menu
- Pause Menu
- Loading Screen
- Settings
- Credits

### Resource Manager

The Resource Manager is responsible for the centralized management of engine resources.

Current Responsibilities

- Initialize resource system
- Shutdown resource system
- Register resources
- Query registered resources

Future Responsibilities

- Texture management
- Sprite sheets
- Fonts
- Audio
- Configuration files
- Save-game metadata

## Core Principles

### Architecture Before Features

Build a strong foundation before adding new capabilities.

---

### One Responsibility Per System

Each subsystem should have one clearly defined purpose.

---

### Performance First

Performance should be considered during design, not as a later optimization.

---

### Modularity

Systems should be reusable, replaceable, and loosely coupled whenever practical.

---

### Incremental Development

Large features should be built through small, stable milestones.

---

### Documentation

Documentation evolves alongside the engine.

---

### Version Stability

Every released version should compile, execute correctly, and represent a stable milestone.

---

### Long-Term Maintainability

Code should remain understandable months and years after it is written.

## The Fawn Test

Every major feature should answer the following questions:

1. Does it improve the engine?
2. Can it benefit multiple future games?
3. Can it run efficiently on target hardware?
4. Can it remain modular?
5. Is the maintenance cost justified?

If the answer is no:

- Optimize it.
- Make it optional.
- Or leave it out.

## Development Workflow

Every version follows the same lifecycle.

1. Planning
2. Architecture
3. Implementation
4. Compilation
5. Testing
6. Documentation
7. Git Commit
8. Git Push

A version is not complete until every step has been finished successfully.

## Long-Term Goals

The long-term objective of Fawn Engine is to become a lightweight, modular, performance-first game engine capable of creating complete commercial-quality games.

The engine is designed around the following priorities:

- Performance
- Simplicity
- Modularity
- Maintainability
- Stability
- Scalability

Rather than pursuing feature parity with existing engines, Fawn Engine will implement advanced capabilities only when they align with the engine's philosophy and performance goals.

Future systems should be designed to support multiple games without requiring modifications to the engine core.

## Target Hardware

Fawn Engine is designed to perform efficiently across a wide range of hardware.

Primary design targets include:

- Raspberry Pi 5-class systems
- Mini PCs
- Older laptops
- Entry-level desktop computers
- Modern desktop systems

The engine should scale upward to more powerful hardware while maintaining excellent performance on modest systems.

Performance improvements should never unnecessarily increase minimum hardware requirements.

## Engine Layers

Fawn Engine is organized into layered subsystems.

Engine
│
├── Core
│ ├── Time
│ ├── Game
│ ├── SceneManager
│ └── ResourceManager
│
├── World
│
├── Entities
│
├── Rendering
│
└── Input

