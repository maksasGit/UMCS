import matplotlib as mpl
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

grid_size = 50
Z = np.random.rand(grid_size, grid_size)
Z[Z>0.5] = 1
Z[Z!=1] = 0

fig, ax = plt.subplots()
mat = ax.matshow(Z , cmap="plasma")

def animate(frame, Z):
    Z_copy = Z.astype(np.int32)
    neighbors = sum(np.roll(np.roll(Z_copy, i, 0), j, 1)
                    for i in (-1, 0, 1) for j in (-1, 0, 1)
                    if (i != 0 or j != 0))
    Z_copy = (neighbors == 3) | (Z_copy & (neighbors == 2)).astype(np.int32)
    mat.set_data(Z_copy)
    return [mat]


anima = FuncAnimation(fig , animate, frames=100, fargs=(Z,))
plt.show()
