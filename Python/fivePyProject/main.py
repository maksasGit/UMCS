import numpy as np
import matplotlib.pyplot as plt

# Parametry generowania zbioru Mandelbrota
width, height = 800, 800
x_min, x_max = -2.5, 1
y_min, y_max = -1, 1
max_iterations = 1000

# Tworzenie siatki pikseli
x = np.linspace(x_min, x_max, width)
y = np.linspace(y_min, y_max, height)
X, Y = np.meshgrid(x, y)
Z = X + 1j * Y

# Inicjalizacja macierzy wynikowej i kolejki
mandelbrot_set = np.zeros((height, width))
queue = np.zeros((height, width), dtype=bool)
queue.fill(True)

# Generowanie zbioru Mandelbrota
for i in range(max_iterations):
    Z[queue] = Z[queue] * Z[queue] + X[queue] + 1j * Y[queue]
    escaped = np.abs(Z) > 2
    mandelbrot_set[queue & escaped] = i
    queue &= ~escaped

# Sortowanie kolejki
sorted_queue = np.argsort(mandelbrot_set, axis=None)
sorted_indices = np.unravel_index(sorted_queue, mandelbrot_set.shape)

# Wyświetlanie zbioru Mandelbrota
plt.figure(figsize=(8, 8))
plt.imshow(mandelbrot_set, cmap='hot', extent=(x_min, x_max, y_min, y_max))
plt.colorbar(label='Iterations')
plt.scatter(X[sorted_indices], Y[sorted_indices], s=0.1, c='green')
plt.title('Mandelbrot Set')
plt.xlabel('Re(c)')
plt.ylabel('Im(c)')
plt.show()
