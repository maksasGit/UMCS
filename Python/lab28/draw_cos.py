import matplotlib as mpl
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

x = np.random.rand(50,50)
n = 100
ln = np.linspace(0,n,n)
X,Y= np.meshgrid(ln,ln)
Z = 100*2 - ((50-X)**2 + (Y-50)**2)

plt.matshow(Z)
plt.show()