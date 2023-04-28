import matplotlib as mpl
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

grid_size = 50
X,Y = np.meshgrid(np.linspace(-np.pi/2, np.pi/2 , grid_size),
                  np.linspace(-np.pi/2, np.pi/2 , grid_size))

Z=np.sin(X)*np.cos(Y)

def anima(frame, X, Y, Z):
    Z = np.sin(X+np.sin(frame/10)) * \
        np.cos(Y-np.sin(frame/20)) + \
        np.sin(X-Y)*np.cos(frame/10)
    mat.set_data(Z)
    return mat

fig, ax = plt.subplots()
mat = ax.matshow(Z)
anima = FuncAnimation(fig, anima, frames=200,
                      fargs=(X,Y,Z), interval=5 )

plt.show()