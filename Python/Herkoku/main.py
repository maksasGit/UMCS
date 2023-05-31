import data
from NN import *
from data import *


data_set = [6, 7, 11, 17, 18, 20, 21, 23, 24, 25]
data_obj = Data('letters.data', data_set)
data_obj.solve_data()

net = SLP()

net.fit(data_obj.my_pixels , data_obj.my_expected_outputs)
net.predict(data_obj.my_pixels)
print(net.errors_)
damaged5 = damage(data_obj.my_pixels,5)
damaged15 = damage(data_obj.my_pixels,15)
damaged40 = damage(data_obj.my_pixels,40)
print(net.misclassified(data_obj.my_pixels, data_obj.my_expected_outputs))
print(net.misclassified(damaged5, data_obj.my_expected_outputs))
print(net.misclassified(damaged15, data_obj.my_expected_outputs))
print(net.misclassified(damaged40, data_obj.my_expected_outputs))


# newSLP = SLP()
# X_train = np.concatenate((data_obj.my_pixels, damaged5, damaged15))
# y_train = np.concatenate((data_obj.my_expected_outputs, data_obj.my_expected_outputs, data_obj.my_expected_outputs))
#
# # Fit the neural network
# newSLP.fit(X_train, y_train)
#
# # Print the errors and misclassified examples
# print(newSLP.errors_)
# print(newSLP.misclassified(data_obj.my_pixels, data_obj.my_expected_outputs))
# print(newSLP.misclassified(damaged5, data_obj.my_expected_outputs))
# print(newSLP.misclassified(damaged15, data_obj.my_expected_outputs))
# print(newSLP.misclassified(damaged40, data_obj.my_expected_outputs))