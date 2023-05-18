import numpy as np
import matplotlib.pyplot as plt

weights = []

class Perceptron:
    def __init__(self, eta=0.0001, n_iter=2000, random_state=1):
        self.eta = eta
        self.n_iter = n_iter
        self.random_state = random_state

    def fit(self, X, y):
        rgen = np.random.RandomState(self.random_state)
        self.w_ = rgen.normal(loc=0.0, scale=0.01, size=1 + X.shape[1])
        self.errors_ = []
        weights.append(list(self.w_))
        for _ in range(self.n_iter):
            errors = 0
            for xi, target in zip(X, y):
                update = self.eta * (target - self.predict(xi))
                self.w_[1:] += update * xi
                self.w_[0] += update
                errors += int(update != 0.0)
            self.errors_.append(errors)
            weights.append(list(self.w_))
        return self

    def net_input(self, X):
        return np.dot(X, self.w_[1:]) + self.w_[0]

    def predict(self, X):
        return np.where(self.net_input(X) >= 0.0, 1, -1)


X = np.array([[1, 0], [0, 123], [1, 23], [0, 0], [1, 1], [0, 1] , [1,200], [0,200]   ])
Y = np.array([[1],    [-1],     [1],     [-1],   [1],    [-1],    [1] ,    [-1]   ])
ppn = Perceptron()
ppn.fit(X, Y)
X_new = np.array([[0, 12], [0, 1323], [1, 0], [0, 1], [1, 22] , [1,1000]])
print(ppn.predict(X_new))

weights = np.array(weights)  # Convert weights list to numpy array

plt.figure()
epochs = range(len(weights))
print(weights[len(weights)-1])
for i in range(weights.shape[1]):
    plt.plot(epochs, weights[:, i], label=f'Weight {i+1}')
plt.xlabel('Epochs')
plt.ylabel('Weight')
plt.legend()
plt.show()



