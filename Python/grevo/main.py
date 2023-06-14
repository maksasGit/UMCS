import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from genetic import Eugenics

data_path = 'data/iris.data'
data = pd.read_csv(data_path, header=None)
X_data = data.iloc[:, :2].values
Y_data = data.iloc[:, -1].values
label_encoder = LabelEncoder()
Y_data = label_encoder.fit_transform(Y_data)
new_array = [[-1, -1, -1] for _ in range(len(Y_data))]
for i, y in enumerate(Y_data):
    new_array[i][y] = 1
Y_data = new_array

X_train, X_test, Y_train, Y_test = train_test_split(X_data, Y_data, test_size=0.2, random_state=42)


mem = Eugenics()
mem.start_train(X_train, Y_train)
