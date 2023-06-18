import numpy as np
import matplotlib.pyplot as plt


rule = 90
num_generations = 100
width = 2 * num_generations + 1
initial_state = np.zeros(width, dtype=int)
initial_state[num_generations] = 1
generations = np.zeros((num_generations, width), dtype=int)
generations[0] = initial_state
for i in range(1, num_generations):
    for j in range(1, width - 1):
        generations[i, j] = (rule >> (4 * generations[i-1, j-1] + 2 * generations[i-1, j] + generations[i-1, j+1])) & 1
plt.figure(figsize=(8, 8))
plt.imshow(generations, cmap='binary', aspect='auto')
plt.axis('off')
plt.show()
