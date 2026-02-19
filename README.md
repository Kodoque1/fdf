*This project has been created as part of the 42 curriculum by zaddi.*

## Description

FDF (Fil de Fer) is a 3D graphics project that reads height map data from `.fdf` files and displays them as isometric wireframe projections. The project demonstrates fundamentals of:

- **3D Graphics Rendering**: Converting 3D coordinates to 2D screen space using isometric projection
- **Line Drawing**: Implementing Bresenham's line algorithm for pixel-perfect rendering
- **Color Interpolation**: Creating smooth color gradients based on elevation (white for low points, violet for high points)
- **Memory Management**: Proper allocation and deallocation of map data structures, as well as ressources created by the MLX library
- **Event Handling**: Keyboard and window close event detection

The program reads heightmap files and renders them as interconnected wireframe structures, providing a visual representation of terrain or mathematical surfaces.

### Features

- **Isometric Projection**: 3D to 2D coordinate transformation for an angled view
- **Color Gradients**: Elevation-based coloring from white (lowest) to violet (highest)
- **Proper Cleanup**: Complete resource liberation on exit with error handling
- **Multiple Map Support**: Can load and render various `.fdf` map files
- **Keyboard Controls**: ESC and Q keys to exit the program

## Instructions

### Compilation

```bash
cd fdf
make
```

This will:
1. Compile the MLX graphics library
2. Compile all source files with strict error checking (`-Werror -Wextra -Wall`)
3. Link against libft, libprintf, and get_next_line libraries
4. Generate the `fdf` executable

### Installation

The project requires X11 development libraries. Install them with:

```bash
sudo apt-get install libx11-dev libxext-dev libbsd-dev zlib1g-dev
```

### Execution

```bash
./fdf <map_file.fdf>
```

Example:
```bash
./fdf test_maps/42.fdf
./fdf test_maps/pyramide.fdf
```

**Supported File Format**: Text files with `.fdf` extension containing space-separated integers representing heights at each grid position.

### Map File Format

```
0  0  0  0  0
0  1  2  1  0
0  2  4  2  0
0  1  2  1  0
0  0  0  0  0
```

Each integer represents the Z-coordinate (height) at that position. Coordinates are automatically scaled and centered on screen.

## Resources

### Documentation & References
- **Wikipedia article on isometric projection*:  https://en.wikipedia.org/wiki/Isometric_projection
- **Online MLX documentation**: https://harm-smits.github.io/42docs/libs/minilibx
  - Classic technique used in ASCII games and early graphics
- **Rosetta code bresenham implementation**: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm

### How AI Was Used

AI (Claude Copilot) assisted with:

1. **Memory Management Review** (Resource Liberation)
   - Identified and fixed memory leaks in `init_contiguous()`
   - Added proper error handling in `parse_map()` with cleanup on failure
   - Ensured graphics resources are freed on all exit paths

2. **Code Structure & Refactoring**
   - Extracted helper functions (`init_graphics()`, `cleanup_and_exit()`) to keep `main()` under 25 lines
   - Consolidated duplicate cleanup logic between `close_window()` and normal exit
   - Improved code organization and readability

3. **Input Validation**
   - Added proper error handling for map parsing failures

## Technical Choices

### Data Structure
- **Contiguous Memory Allocation**: All map points are allocated as one contiguous block, with a pointer array for 2D access
  - Benefits: Better cache locality, single free operation for all points
  - Implemented in `init_contiguous()` with proper error checking

### Cleanup Strategy
- **Forward Cleanup**: `cleanup_and_exit()` handles all resource deallocation
- **Multiple Exit Paths**: Cleanup occurs in both `close_window()` callback and after `mlx_loop()`
- **Null Checks**: Prevent double-free errors with NULL pointer validation

### Projection Method
- **Isometric View**: Fixed 45-degree rotation for consistent perspective
- **Scaling**: Automatic scaling to fit screen dimensions
- **Centering**: Maps are centered in the 800x600 window

## Testing

Test various map files:
```bash
./fdf test_maps/42.fdf          # The 42 logo
./fdf test_maps/pyramide.fdf    # Pyramid structure
./fdf test_maps/mars.fdf        # Martian terrain
```

## Cleaning

Remove compiled objects:
```bash
make clean       # Remove object files
make fclean      # Remove objects and executable
make re          # Full rebuild
```

## Project Structure

```
fdf/
├── main.c              # Entry point with event handling
├── fdf_parse.c         # Map file parsing logic
├── ft_3d.c             # 3D transformations
├── ft_draw_map.c       # Rendering pipeline
├── ft_draw_utils.c     # Line drawing (Bresenham)
├── ft_interpolate.c    # Color interpolation and elevation-based coloring
├── ft_utils.c          # Utility functions (map allocation/deallocation)
├── libft/              # Custom C library
├── libprintf/          # Custom printf implementation
├── gnl/                # Get next line (file reading)
└── mlx/                # Graphics library
```

## Notes

- The program uses MLX library for graphics, which requires X11
- Keyboard and window close events are handled through MLX hooks
- Color gradient provides visual feedback on terrain elevation
- All dynamically allocated memory is properly freed on exit
