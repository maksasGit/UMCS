import numpy as np
import pandas as pd
import os
import matplotlib.pyplot as plt
#from google.colab import files
import io

color_map = plt.colormaps['gray']
reversed_color_map = color_map.reversed()

# uploaded = files.upload()
# df = pd.read_csv(io.BytesIO(uploaded['letters.data']), header=None)

class Perceptron(object):

  def __init__(self, eta = 0.001, n_iter=50, random_state = 1):
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

  def __init__(self, eta=0.05, n_iter=10, random_state=1):
    self.eta  = eta
    self.n_iter = n_iter
    self.random_state = random_state


  def fit(self, X, y):
    self.errors_ = None
    self.network = []
    for i in range(0,len(X)):
      self.network.append(Perceptron(eta = self.eta, n_iter = self.n_iter, random_state= self.random_state))
    for i in range(0,len(X)):
      self.network[i].fit(X,y[i])
      if self.errors_ == None:
        self.errors_ = np.array([self.network[i].errors_])
      else:
        self.errors_ += np.array([self.network[i].errors_])
      self.errors_ = list(self.errors_)
    return self.network


  def predict(self, X):
    self.predictedArr = []
    for i in range(0,len(X)):
      self.predictedArr.append(self.network[i].predict(X))
    return self.predictedArr


  def misclassified(self, X,y):
    predictedForCompare = self.predict(X)
    mis = 0
    for i in range(0,len(X)):
      for j in range(0,len(X)):
        if predictedForCompare[i][j] != y[i][j]:
          mis +=1
    return mis


  def show(self, X):
      fi,ax = plt.subplots(nrows = 2, ncols = int(len(X)/2),figsize = (25,0))
      k = 0
      for i in range(0,2):
        for j in range(0,int(len(X)/2)):
          row = X[k]
          k += 1
          arrForDraw = np.array([])
          for m in range (0,35):
            arrForDraw = np.append(arrForDraw,row[m])
          ax[i][j].imshow(arrForDraw.reshape(7,5),cmap=reversed_color_map)
          ax[i][j].axis('off')