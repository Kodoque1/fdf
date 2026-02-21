*This project has been created as part of the 42 curriculum by zaddi.*

## Description

FDF (Fil de Fer) is a 3D graphics project that reads height map data from `.fdf` files and displays them as isometric wireframe projections. The goal is to create a graphical representation of terrain or mathematical surfaces by converting 3D coordinates to 2D screen space.

The project demonstrates fundamentals of:
- **3D Graphics Rendering**: Converting 3D coordinates to 2D screen space using isometric projection
- **Line Drawing**: Implementing Bresenham's line algorithm for pixel-perfect rendering
- **Color Interpolation**: Creating smooth color gradients based on elevation (white for low points, violet for high points)
- **Memory Management**: Proper allocation and deallocation of map data structures and MLX library resources
- **Event Handling**: Keyboard (ESC) and window close event detection

The program reads heightmap files where each integer represents a Z-coordinate (height) at a grid position, then renders them as interconnected wireframe structures with automatic scaling and centering in an 800x600 window.

## Instructions

### Installation

The project requires X11 development libraries. Install them with:

```bash
sudo apt-get install libx11-dev libxext-dev libbsd-dev zlib1g-dev
```

### Compilation

```bash
cd fdf
make
```

This will compile the MLX graphics library, all source files with strict error checking (`-Werror -Wextra -Wall`), link against libft, libprintf, and get_next_line libraries, and generate the `fdf` executable.

### Execution

```bash
./fdf <map_file.fdf>
```

Example:
```bash
./fdf test_maps/42.fdf
./fdf test_maps/pyramide.fdf
./fdf test_maps/mars.fdf
```

**Controls**: Press ESC or click the window close button to exit.

**File Format**: `.fdf` text files containing space-separated integers representing heights at each grid position.

## Resources

### Documentation & References
- **Isometric Projection**: https://en.wikipedia.org/wiki/Isometric_projection - Mathematical explanation of the 3D to 2D transformation technique
- **MLX Documentation**: https://harm-smits.github.io/42docs/libs/minilibx - Reference for the MinilibX graphics library functions and hooks
- **Bresenham's Line Algorithm**: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm - Implementation guide for efficient line drawing

### How AI Was Used

AI (GitHub Copilot with Claude Sonnet 4.5) assisted throughout development with:

1. **Bug Identification and Fixes**
   - Identified isometric projection bug where modified x-coordinate was used in y-calculation
   - Fixed memory leaks in MLX resource cleanup (missing `mlx_destroy_display` calls)
   - Resolved crash from trailing spaces in map files by refactoring line parsing logic

2. **Code Quality & Standards Compliance**
   - Enforced 42 School norm compliance (25-line function limit, 5-function file limit)
   - Split oversized functions (`draw_line`, `rows_and_columns_size`, `main`)
   - Created `fdf_parse_utils.c` and `main_utils.c` to distribute functions across files
   - Removed redundant validations identified through code review

3. **Memory Management & Resource Handling**
   - Added NULL checks for malloc failures in `create_point()`
   - Implemented proper cleanup on all error paths in `parse_map()`
   - Ensured complete resource deallocation with `cleanup_and_exit()` function
   - Fixed allocation logic to prevent buffer overflows

4. **Code Structure & Refactoring**
   - Extracted utility functions (`strip_newline`, `process_entry`, `process_line`)
   - Separated event handlers and cleanup routines into dedicated files
   - Improved code organization for maintainability and readability
