import matplotlib as mpl
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

grid_size = 100
Z = np.random.rand(grid_size, grid_size)
Z[Z>0.5] = 1
Z[Z!=1] = 0

fig, ax = plt.subplots()
mat = ax.matshow(Z , cmap="plasma")

def anima(frame, Z):
    Z_copy = np.zeros((grid_size, grid_size))
    for i in range(grid_size):
        for j in range(grid_size):
            neighbors = Z[i-1:i+2, j-1:j+2].sum() - Z[i, j]
            if Z[i, j] == 1 and neighbors in {2, 3}:
                Z_copy[i, j] = 1
            if Z[i, j] == 0 and neighbors == 3:
                Z_copy[i, j] = 1
    Z[:] = Z_copy[:]
    mat.set_data(Z_copy)
    return mat




anima = FuncAnimation(fig , anima, frames=100, fargs=(Z,) , interval=10)
plt.show()
