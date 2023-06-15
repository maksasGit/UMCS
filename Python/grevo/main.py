import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from genetic import Eugenics

# #
# s = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
# print('URL:', s)
# df = pd.read_csv(s, header=None, encoding='utf-8')
# X_data = df.iloc[0:150, [0, 2]].values
# X_data[100:150] += [2, -3]
# Y_data = df.iloc[0:150, 4].values
# label_encoder = LabelEncoder()
# Y_data = label_encoder.fit_transform(Y_data)
# new_array = [[-1, -1, -1] for _ in range(len(Y_data))]
# for i, y in enumerate(Y_data):
#     new_array[i][y] = 1
# Y_data = new_array


# print(X_data)
# print(Y_data)
#
# plt.scatter(X_data[:50, 0], X_data[:50, 1], color='red', marker='o', label='setosa')
# plt.scatter(X_data[50:100, 0], X_data[50:100, 1], color='blue', marker='x', label='versicolor')
# plt.scatter(X_data[100:150, 0], X_data[100:150, 1], color='green', marker='^', label='virginica')
# plt.xlabel('sepal length [cm]')
# plt.ylabel('petal length [cm]')
# plt.legend(loc='upper left')
# plt.show()


# X_train, X_test, Y_train, Y_test = train_test_split(X_data, Y_data, test_size=0.2, random_state=42)

#
# mem = Eugenics()
# mem.start_train(X_data, Y_data)
# print(mem.missclassified(X_data,Y_data))

letters_path = 'data/letters.data'


data = pd.read_csv(letters_path)
all_pixels = data.iloc[:, :35].values
all_outputs = data.iloc[:, 35:].values
my_pixels = np.array([])
my_outputs = np.array([])
# My set [6, 7, 11, 17, 18, 20, 21, 23, 24, 25]
example_set = [6, 7, 11, 17, 18, 20, 21, 23, 24, 25]
print(all_pixels)
print(all_outputs)

for id in example_set:
    my_pixels = np.append(my_pixels, all_pixels[id-1])
    outputs = np.array([])
    for id2 in example_set:
      outputs = np.append(outputs, all_outputs[id-1][id2])
    my_outputs = np.append(my_outputs, outputs)

my_pixels = my_pixels.reshape((-1, 35))
my_outputs = my_outputs.reshape((-1, 10))
print(my_outputs)
kek = Eugenics()
kek.start_train(my_pixels , my_outputs)
print(kek.missclassified(my_pixels, my_outputs))
# [ 0.   -0.56 -0.32  0.88  0.16 -0.16  0.96 -0.5  -0.84]  -  0.9933333333333333