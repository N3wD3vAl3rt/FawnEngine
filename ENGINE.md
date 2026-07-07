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