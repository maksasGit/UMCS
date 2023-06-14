import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

s = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
print('URL:', s)
df = pd.read_csv(s, header=None, encoding='utf-8')
X = df.iloc[0:150, [0, 2]].values

X[100:150] += [2, -3]
y = df.iloc[0:150, 4].values

for i in range(len(y)):
    if y[i] == 'Iris-setosa':
        y[i] = [1, -1, -1]
    elif y[i] == 'Iris-versicolor':
        y[i] = [-1, 1, -1]
    else:
        y[i] = [-1, -1, 1]


print(X)
print(y)

plt.scatter(X[:50, 0], X[:50, 1], color='red', marker='o', label='setosa')
plt.scatter(X[50:100, 0], X[50:100, 1], color='blue', marker='x', label='versicolor')
plt.scatter(X[100:150, 0], X[100:150, 1], color='green', marker='^')
plt.xlabel('sepal length [cm]')
plt.ylabel('petal length [cm]')
plt.legend(loc='upper left')
plt.show()

class GenAlg(object):
    def __init__(self, genSize=9, maxIter=240, popSize=100):
        self.genSize = genSize
        self.maxIter = maxIter
        self.popSize = popSize
        self.best_individuals = []
        self.average_qualities = []

    def generate_individual(self):
        gen = []
        for i in range(self.genSize):
            gen.append(np.round(np.random.uniform(-1, 1), 2))
        return np.array(gen)

    def initialize_population(self):
        self.population = [self.generate_individual() for _ in range(self.popSize)]

    def softmax(self, X):
        return np.where(X >= 0.0, 1, -1)

    def evaluate_individual(self, individual, X, Y):
        weights = individual[:6].reshape(3, 2)
        biases = individual[6:].reshape(3)
        correct_answers = 0
        for i in range(len(X)):
            x = X[i].reshape(len(X[0]))
            y_expected = Y[i]
            # print("!",weights)
            # print(">",x)
            # print("?",biases)
            y_obtained = np.dot(weights, x) + biases
            # print(":",y_obtained)
            y_obtained = self.softmax(y_obtained)
            for item, expected in zip(y_obtained, y_expected):
                if (item == expected).all():
                    correct_answers += 1
        return correct_answers

    def predict(self, X):
        weights = self.population[0][:6].reshape(3, 2)
        biases = self.population[0][6:].reshape(3)
        predicted = []
        for i in range(len(X)):
            x = X[i].reshape(len(X[0]))
            y_obtained = np.dot(weights, x) + biases
            y_obtained = self.softmax(y_obtained)
            predicted.append(y_obtained)
        return predicted

    def evaluate_population(self, population, X, Y):
        positive_population = [self.evaluate_individual(individual, X, Y) for individual in population]
        sorted_indices = sorted(range(len(positive_population)), key=lambda i: positive_population[i], reverse=True)
        sorted_population = [population[i] for i in sorted_indices]
        sorted_positive_population = [positive_population[i] for i in sorted_indices]
        self.population = sorted_population
        return self.population, sorted_positive_population

    def generate_next_population(self, population):
        next_population = population[:self.popSize // 10]
        for _ in range(self.popSize - len(next_population)):
            parents_idx = np.random.choice(self.popSize // 2, 2, replace=False)
            parent1, parent2 = population[parents_idx[0]], population[parents_idx[1]]
            child = []
            for i in range(self.genSize):
                rand = np.random.rand()
                if rand > 0.9:
                    child.append(np.round(np.random.uniform(-1, 1), 2))
                elif rand > 0.45:
                    child.append(parent1[i])
                else:
                    child.append(parent2[i])
            next_population.append(np.array(child))
        return next_population

    def fit(self, X, y):
        self.initialize_population()
        for iteration in range(self.maxIter):
            print(iteration)
            population, positive_population = self.evaluate_population(self.population, X, y)
            self.best_individuals.append(positive_population[0])
            self.average_qualities.append(np.mean(positive_population))
            if positive_population[0] == len(X) * 3:
                break
            self.population = self.generate_next_population(population)

    def missclassified(self, X, y):
        predicted = self.predict(X)
        bad = 0
        for predict, expect in zip(predicted, y):
            for pred, exp in zip(predict, expect):
                if pred != exp:
                    bad += 1
        return bad


# G = GenAlg()
# G.fit(X, y)
# print(G.population)
#
# plt.figure()
# plt.plot(G.best_individuals, label="Best individual")
# plt.plot(G.average_qualities, label="Average quality")
# plt.xlabel("Generation")
# plt.ylabel("Quality measure")
# plt.legend()
# plt.show()
#
# print(G.predict(X))
# print(G.missclassified(X, y))
