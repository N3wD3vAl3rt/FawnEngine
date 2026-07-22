# Fawn Engine

*A lightweight, modular, performance-first game engine.*

---

## Overview

Fawn Engine is a custom game engine written in modern C++ with a focus on performance, simplicity, and maintainability. It is being developed from the ground up as a long-term engineering project with the goal of powering complete commercial-quality games.

Rather than pursuing feature parity with existing engines, Fawn Engine emphasizes clean architecture, reusable systems, and incremental development.

---

## Current Status

**Current Version:** v0.10.1

Fawn Engine is under active development.

The engine currently provides the core foundation required for future gameplay systems, including rendering, asset management, scene management, timing, and animation support.

---

## Features

### Core

- Engine framework
- Game abstraction layer
- Version system
- Build information
- High-resolution timing (`deltaTime`)
- Scene management
- Resource management

### Rendering

- Software renderer
- Image loading
- Texture system
- Sprite rendering
- Sprite sheets
- Camera system

### Gameplay

- Entity framework
- Player
- Enemy
- Animation system
- Frame-rate independent movement

### Input

- Keyboard input
- Mouse input

---

## Project Philosophy

Fawn Engine follows a simple philosophy:

- Performance first
- Simplicity over complexity
- Modular architecture
- Stable APIs
- Incremental development
- Long-term maintainability

Every new subsystem must improve the engine while remaining reusable across multiple games.

---

## Current Architecture

```
Engine
│
├── Core
│   ├── Time
│   ├── Game
│   ├── SceneManager
│   └── ResourceManager
│
├── Rendering
│   ├── Renderer
│   ├── Image
│   ├── Texture
│   ├── Sprite
│   └── SpriteSheet
│
├── World
│
├── Entities
│
├── Animation
│
├── Camera
│
└── Input
```

---

## Roadmap

### v0.10.2

- Animation integration
- Asset-driven entities
- Animated player
- Animated enemies

### v0.10.3

- Tile map system
- World rendering
- Camera culling

### v0.10.4

- Physics
- Collision
- Raycasting

### v0.10.5

- Audio system

### v0.10.6

- User interface

### v0.11.0

- Gameplay framework

### v1.0.0

- Fawn Engine Showcase

---

## Build Requirements

### Platform

- Windows

### Compiler

- Microsoft Visual Studio 2022
- C++20

---

## Project Structure

```
FawnEngine/
│
├── Assets/
├── Docs/
├── Engine/
├── Game/
├── LICENSE
├── README.md
├── ENGINE.md
└── CHANGELOG.md
```

*(Project structure may evolve as development continues.)*

---

## Documentation

- **README.md** — Project overview
- **ENGINE.md** — Design specification and engineering philosophy
- **CHANGELOG.md** — Version history

---

## Development Workflow

Every release follows the same process:

1. Planning
2. Architecture
3. Implementation
4. Compilation
5. Testing
6. Documentation
7. Version update
8. Git commit
9. Git push

A version is considered complete only after all steps have been successfully finished.

---

## Long-Term Vision

The goal of Fawn Engine is to become a lightweight, high-performance engine capable of building complete commercial-quality games while remaining approachable, maintainable, and enjoyable to develop with.

The first public milestone will be the **Fawn Engine Showcase**, demonstrating the engine's architecture, performance, and capabilities through a complete game.

---

## License

This project is currently under development.

A license will be selected before the first public release.