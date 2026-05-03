*This project has been created as part of the 42 curriculum by synoshah.*

# so_long

## Description
**so_long** is a small 2D game I built with Minilibx. You are the player (P), and you need to collect all the collectibles (C) on the map before going through the exit (E).

In the bonus version, there are enemies that patrol the map and you lose if you touch them. The game also has simple animations, so it feels more alive, and the move counter is shown directly in the game window.

You can move through empty spaces (0) but not walls (1). Every move you make is counted (printed to the terminal in the mandatory version, displayed in the window in the bonus version).

## Instructions

### Requirements
Runs on Linux. Requires X11 headers and minilibx.

### Build & Run
1. **Compile:** `make`
2. **Run:** `./so_long maps/map.ber`
3. **Build bonus:** `make bonus`
4. **Run bonus:** `./so_long_bonus maps/map2.ber`
5. **Check for leaks:** `valgrind ./so_long maps/map.ber`

## Resources
- MiniLibX documentation (42 intranet / school docs)

### AI Usage
1. Correcting library paths in the Makefile for MiniLibX linking.
2. Proofreading the README.
3. Fixing edge cases and checking for leaks.
