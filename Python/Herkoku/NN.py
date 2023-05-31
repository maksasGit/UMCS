import math

import numpy as np
import pandas as pd
import os
import matplotlib.pyplot as plt
#from google.colab import files
import io
import networkx as nx


color_map = plt.colormaps['gray']
reversed_color_map = color_map.reversed()

# uploaded = files.upload()
# df = pd.read_csv(io.BytesIO(uploaded['letters.data']), header=None)

class Perceptron(object):

  def __init__(self, eta = 0.01, n_iter=30, random_state = 1):
    self.eta = eta
    self.n_iter = n_iter
    self.random_state = random_state

  def fit(self,X, y):
    rgen = np.random.RandomState(self.random_state)
    self.w_ = rgen.normal(loc = 0.0, scale = 0.01, size = 1 + X.shape[1])
    self.errors_ = []
    for _ in range(self.n_iter):
      errors = 0
      for xi , target in zip(X,y):
        update = self.eta * (target - self.predict(xi))
        self.w_[1:] += update * xi
        self.w_[0] += update
        errors += int(update != 0.0)
      self.errors_.append(errors)
    return self

  def net_input(self,X):
    return np.dot(X, self.w_[1:]) + self.w_[0]

  def predict(self, X):
    return np.where(self.net_input(X) >= 0.0, 1, -1)



class SLP(object):
  def __init__(self, eta=0.001, n_iter=10, random_state=1):
    self.eta  = eta
    self.n_iter = n_iter
    self.random_state = random_state

  def fit(self, X, y):
    self.errors_ = np.zeros(y[0].shape)
    self.perceptrons = [Perceptron(eta=self.eta, n_iter=self.n_iter, random_state=self.random_state) for _ in range(len(X))]
    for perceptron, outputs in zip(self.perceptrons, y):
      perceptron.fit(X, outputs)
      self.errors_ += perceptron.errors_
    return self.perceptrons


  def predict(self, X):
      return [perceptron.predict(X) for perceptron in self.perceptrons]

  def misclassified(self, X, y):
    slp_out = np.array(self.predict(X))
    corr_out = np.array(y)
    mistake = np.sum(slp_out != corr_out)
    return mistake

  def show(self, X):
    num_images = len(X)
    num_rows, num_cols = (5, 2)
    total_plots = num_rows * num_cols

    num_plots = min(num_images, total_plots)
    figsize = (4 * num_cols, 4 * math.ceil(num_plots / num_cols))

    fig, axes = plt.subplots(num_rows, num_cols, figsize=figsize)
    fig.tight_layout()

    for i, ax in enumerate(axes.flatten()):
      if i < num_images:
        image = X[i].reshape(7, 5)
        ax.imshow(image, cmap='gray_r')
        ax.axis('off')
      else:
        ax.axis('off')

    plt.show()



def damage(X,percent,seed = 1):
  rgen = np.random.RandomState(seed)
  result = np.array(X)
  count = int(X.shape[1]*percent/100)

  for index_example in range(len(X)):
    order = np.sort(rgen.choice(X.shape[1],count,replace = False))
    for index_pixel in order:
      result[index_example][index_pixel] *=-1

  return result