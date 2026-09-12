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
