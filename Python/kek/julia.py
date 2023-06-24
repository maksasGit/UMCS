import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

zoom = 2
width = 400
height = 400
max_iterations = 100
interval = 100
num_frames = 100

def animate_set(width, height, c, max_iterations):
    x, y = np.meshgrid(np.linspace(-zoom, zoom, width), np.linspace(-zoom, zoom, height))
    Z = (x + 1j * y)
    img = np.zeros((height, width))
    for _ in range(max_iterations):
        mask = np.abs(Z) < 4
        Z[mask] = Z[mask] * Z[mask] + c
        img += mask
    return img

fig, ax = plt.subplots(figsize=(8, 8))
c_values = np.exp(2j * np.pi * np.linspace(0, 1, num_frames))

def update(frame):
    ax.cla()
    julia_set = animate_set(width, height, c_values[frame], max_iterations)
    ax.imshow(julia_set, cmap='hot', extent=(-zoom, zoom, -zoom, zoom))
    ax.axis(False)

ani = animation.FuncAnimation(fig, update, frames=num_frames, interval=interval)
plt.show()
