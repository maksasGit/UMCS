import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.colors import LinearSegmentedColormap

height = 120
width = 160
num_generations = 100
initial_grid = np.random.choice([0, 1], size=(height, width), p=[0.8, 0.2])
generation = np.zeros_like(initial_grid)

color_map = LinearSegmentedColormap.from_list(
    'custom_cmap',
    [(0, (0, 0, 0, 1))] + [(i / (num_generations + 1), plt.cm.viridis(i / (num_generations + 1))) for i in range(num_generations + 2)]
)

fig, ax = plt.subplots(figsize=(6, 6))
ax.set_axis_off()
img = ax.imshow(generation, cmap=color_map, vmin=0, vmax=num_generations + 1, aspect='auto')

def update_grid(grid):
    new_grid = np.copy(grid)
    for i in range(height):
        for j in range(width):
            neighbors = grid[max(0, i-1):min(i+2, height), max(0, j-1):min(j+2, width)]
            num_neighbors = np.sum(neighbors) - grid[i, j]
            if grid[i, j] == 1 and (num_neighbors < 2 or num_neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and num_neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def animate_generation(gen):
    global initial_grid, generation
    old_grid = initial_grid.copy()
    initial_grid = update_grid(initial_grid)
    diff = initial_grid - old_grid
    new_cells = (diff == 1)
    dead_cells = (diff == -1)
    generation[new_cells] = gen
    generation[dead_cells] = 0
    img.set_array(np.where(new_cells, generation + 1, generation))
    return img,

ani = FuncAnimation(fig, animate_generation, frames=range(1, num_generations + 1), interval=50, blit=True)
plt.show()
