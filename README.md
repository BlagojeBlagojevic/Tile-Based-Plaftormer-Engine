
# SDL Game Project

This is a simple SDL-based game written in C. The project includes basic functionality for rendering sprites, handling player input, and implementing game logic for a map and enemies.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Features](#features)
- [Dependencies](#dependencies)
- [License](#license)

## Installation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/yourusername/sdl-game.git
   cd sdl-game
   ```

2. **Install dependencies:**

   Make sure you have the SDL2 and SDL2_image libraries installed on your system. For example, on Ubuntu, you can install them with:

   ```sh
   sudo apt-get install libsdl2-dev libsdl2-image-dev
   ```

3. **Build the project:**

   ```sh
   gcc -o game main.c -lSDL2 -lSDL2_image
   ```

## Usage

Run the game using the following command:

```sh
./game
```

## Project Structure

- `utils.h`: Contains utility functions, macros, and type definitions.
- `sprite.h`: Defines the `Sprite` structure and functions for initializing and rendering sprites.
- `player.h`: Contains the player initialization, rendering, and event handling logic.
- `map.h`: Manages the game map and handles map-related events.
- `enemy.h`: Defines enemy behavior, including initialization, rendering, and event handling.
- `game.h`: The main game loop and initialization functions.

## Features

- **Sprite Rendering:** Load and render sprites with animations.
- **Player Control:** Handle player input and movement.
- **Map Management:** Load and render a game map with collision detection.
- **Enemy AI:** Basic enemy movement and collision detection.
- **Game Loop:** Main game loop with event handling and rendering.

## Dependencies

- SDL2
- SDL2_image

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
```
