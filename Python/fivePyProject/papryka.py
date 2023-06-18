import numpy as np
import matplotlib.pyplot as plt

a = np.array([[0, 0], [0, 0.16]])
b = np.array([[0.85, 0.04], [-0.04, 0.85]])
c = np.array([[0.2, -0.26], [0.23, 0.22]])
d = np.array([[-0.15, 0.28], [0.26, 0.24]])
e = np.array([[0, 0], [0, 0.16]])
f = np.array([[0, 0], [0, 0]])

points = np.zeros((2, 50000))
x, y = 0, 0

for i in range(1, 50000):
    r = np.random.random()
    if r < 0.01:
        x, y = np.dot(a, np.array([x, y]))
    elif r < 0.86:
        x, y = np.dot(b, np.array([x, y])) + np.array([0, 1.6])
    elif r < 0.93:
        x, y = np.dot(c, np.array([x, y])) + np.array([0, 1.6])
    else:
        x, y = np.dot(d, np.array([x, y])) + np.array([0, 0.44])
    points[:, i] = x, y

plt.figure(figsize=(8, 10))
plt.scatter(points[0, :], points[1, :], s=0.1, c='green')
plt.axis('off')
plt.show()
