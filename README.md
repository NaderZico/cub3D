# cub3D

A small raycasting engine and first-person game written in C with MiniLibX, inspired by Wolfenstein 3D. Built at 42 Abu Dhabi.

## What it does
- Renders a 3D perspective from a 2D map using raycasting with textured walls
- Parses a `.cub` configuration file for textures and floor/ceiling colors
- Supports movement (WASD), camera rotation, and mouse look
- Validates the map (walls, player start, allowed characters)

## Build and run
```bash
make
./cub3D maps/<map>.cub
```

```bash
make clean / make fclean / make re
```

Uses a bundled MiniLibX; a display is required to run.

## What I learned
- Raycasting math and column-by-column rendering
- Parsing a custom config file and validating a map
- Event handling, hooks, and frame timing
- Structuring a larger C codebase and managing graphics resources
