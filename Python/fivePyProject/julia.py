import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

width, height = 800, 800
c = complex(-0.7, 0.27)
zoom = 1.5
max_iterations = 256
x = np.linspace(-zoom, zoom, width)
y = np.linspace(-zoom, zoom, height)
X, Y = np.meshgrid(x, y)
Z = X + 1j * Y

fig, ax = plt.subplots(figsize=(6, 6))
ax.set_axis_off()

def update(frame):
    julia_set = np.zeros_like(Z, dtype=int)
    mask = np.ones_like(Z, dtype=bool)
    for i in range(max_iterations):
        Z[mask] = Z[mask]**2 + c
        escaped = np.abs(Z) > 2
        julia_set += np.where(escaped & mask, i, 0)
        mask &= ~escaped
    ax.imshow(julia_set, cmap='hot', extent=(-zoom, zoom, -zoom, zoom))

ani = FuncAnimation(fig, update, frames=range(50), interval=100)
plt.show()
