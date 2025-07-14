# 🌀 Fract-ol: Fractal Visualization

## Overview
**Fract-ol** is a C-based project that visualizes three types of fractals: **Mandelbrot**, **Julia**, and **Burning Ship**. Using the **MiniLibX** library, it renders interactive fractal images with zooming, panning, and color-shifting capabilities. The project demonstrates complex mathematical concepts through graphical representations, handling user inputs for dynamic exploration of fractals.

## Mathematical Background
Fractals are geometric shapes that exhibit self-similarity and complex patterns when zoomed in. This project implements three fractals, each defined by iterative mathematical formulas in the complex plane.

### Mandelbrot Set
The **Mandelbrot Set** is defined for a complex number \( c \), where the sequence:
\[ z_{n+1} = z_n^2 + c \]
with \( z_0 = 0 \), remains bounded (i.e., \( |z_n| \leq 2 \)). Points where the sequence escapes to infinity are colored based on the number of iterations, while points in the set are typically black.

### Julia Set
The **Julia Set** uses a similar iterative formula:
\[ z_{n+1} = z_n^2 + c \]
but with a fixed \( c \) (provided as input parameters) and \( z_0 \) based on the pixel's coordinates. The shape of the Julia set varies with different \( c \), creating diverse patterns.

### Burning Ship Fractal
The **Burning Ship Fractal** modifies the Mandelbrot formula by taking the absolute value of the real and imaginary parts:
\[ z_{n+1} = (|\text{Re}(z_n)| + i|\text{Im}(z_n)|)^2 + c \]
This creates a distinctive, symmetrical fractal resembling a ship on fire.

## Project Features
- **Fractal Types**:
  - Mandelbrot
  - Julia (with customizable parameters)
  - Burning Ship
- **Interactivity**:
  - **Zoom**: Mouse scroll (in/out) to zoom at the cursor position.
  - **Pan**: Arrow keys to move the view.
  - **Color Shift**: 'S' key to cycle through color schemes.
  - **Exit**: ESC key to close the program.
- **Error Handling**: Validates input arguments for correct format and number.
- **Performance**: Efficient rendering with MiniLibX for real-time visualization.

## Implementation Details
The project is structured around a `t_fractol` structure that holds fractal parameters (e.g., zoom, coordinates, iteration count) and MiniLibX resources (window, image, etc.). Key components include:

### Core Functions
- **Initialization**:
  ```c
  void fractal_initialize(t_fractol *f, char **av)
  ```
  Sets up fractal parameters based on command-line arguments (`mandelbrot`, `julia`, or `burning_ship`).

- **Rendering**:
  ```c
  void print_fracal(t_fractol *f)
  ```
  Iterates over each pixel, computes fractal values, and draws the result using `pixel_draw`.

- **Drawing Logic** (e.g., Burning Ship):
  ```c
  static void draw_burning_ship(t_fractol *f)
  {
      double z_next, z_tmp;
      int i;
      f->c_r = f->x / f->zoom + f->x_set;
      f->c_i = -(f->y / f->zoom + f->y_set);
      f->z_r = 0.0;
      f->z_i = 0.0;
      i = 0;
      z_next = 0.0;
      while (z_next < 4 && i < f->max_iter) {
          z_tmp = f->z_r;
          f->z_r = ft_abs(f->z_r * f->z_r - f->z_i * f->z_i + f->c_r);
          f->z_i = ft_abs(2 * f->z_i * z_tmp - f->c_i);
          z_next = f->z_r * f->z_r + f->z_i * f->z_i;
          i++;
      }
      if (i == f->max_iter)
          pixel_draw(f, 0);
      else
          pixel_draw(f, get_color(i, f));
  }
  ```
  Computes the fractal value for each pixel and assigns colors based on iterations.

- **Color Mapping**:
  ```c
  int get_color(int iter, t_fractol *f)
  {
      double t = (double)iter / f->max_iter + f->color_shift;
      int r = (int)(sin(5 * t + 0) * 127 + 128);
      int g = (int)(sin(5 * t + 2) * 127 + 128);
      int b = (int)(sin(5 * t + 4) * 127 + 128);
      return ((r << 16) | (g << 8) | b);
  }
  ```
  Maps iteration counts to RGB colors for vibrant visuals.

### Interactivity
- **Zooming**:
  ```c
  void zoom(int x, int y, t_fractol *f)
  {
      f->x_set = (x / f->zoom + f->x_set) - (x / (f->zoom * 1.5));
      f->y_set = (y / f->zoom + f->y_set) - (y / (f->zoom * 1.5));
      f->zoom *= 1.5;
  }
  ```
  Adjusts the view based on mouse position and zoom factor.

- **Input Handling**:
  Validates Julia set parameters to ensure valid floating-point inputs:
  ```c
  void julia_checker(char *s, t_fractol *f)
  {
      if ((is_number(s)) == 0 || checker(s) > 1) {
          ft_putstr_fd("./fractol_bonus mandelbrot || burning_ship || ", 2);
          ft_putstr_fd("./fractol_bonus julia [+/-00.00] [-/+00.00]\n", 2);
          clear(f);
      }
  }
  ```

## Compilation & Usage
### Prerequisites
- **MiniLibX**: Required for graphical rendering.
- **Compiler**: GCC or Clang.
- **OS**: Linux (MiniLibX is Linux-compatible).

### Compilation
```bash
make
```

### Execution
```bash
./fractol_bonus mandelbrot
./fractol_bonus burning_ship
./fractol_bonus julia [+/-X.XX] [+/-X.XX]
```

### Arguments
| Command          | Description                              | Parameters                     |
|------------------|------------------------------------------|--------------------------------|
| `mandelbrot`     | Renders the Mandelbrot set              | None                           |
| `burning_ship`   | Renders the Burning Ship fractal         | None                           |
| `julia`          | Renders the Julia set                   | Two floats (e.g., `0.285 0.01`)|

### Example
```bash
./fractol_bonus mandelbrot
./fractol_bonus julia 0.285 0.01
```

## Controls
| Key/Action         | Function                     |
|--------------------|------------------------------|
| Mouse Scroll Up    | Zoom in at cursor position   |
| Mouse Scroll Down  | Zoom out at cursor position  |
| Arrow Keys         | Pan (left, right, up, down)  |
| `S`                | Shift color scheme           |
| `ESC`              | Exit the program             |

## Visual Examples
Below are sample renderings of the fractals:

<img width="2560" height="1920" alt="image" src="https://github.com/user-attachments/assets/5cebfa40-ccf0-4434-88a3-527d86acc0b5" />

*The Mandelbrot Set with its characteristic bulbous shapes.*

<img width="2500" height="2500" alt="image" src="https://github.com/user-attachments/assets/aaad4640-2618-4b8a-bfde-162b6c9b69e0" />

*A Julia Set with parameters \( c = 0.355 + 0.355i \).*

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b9d893bb-51af-470c-8684-9f8176bdbf1d" />

<img width="4000" height="4000" alt="image" src="https://github.com/user-attachments/assets/55f35d3d-a8bb-4511-aa6c-973a46b50d33" />

<img width="7440" height="1376" alt="image" src="https://github.com/user-attachments/assets/da074b46-1620-47e6-825b-cca08cda4b5d" />

*The Burning Ship Fractal, showcasing its unique symmetry.*

*Note: Replace placeholder images with actual fractal renderings in your repository.*

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Compile the program:
   ```bash
   make
   ```
3. Run with desired fractal and parameters:
   ```bash
   ./fractol_bonus mandelbrot
   ```

## Dependencies
- **MiniLibX**: Install via your package manager (e.g., `apt-get install libx11-dev libxext-dev` on Ubuntu).
- **Standard C Libraries**: `stdlib.h`, `math.h`, etc.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
