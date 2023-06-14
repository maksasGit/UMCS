import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Perceptron
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

iris_path = 'data/iris.data'

iris = load_iris()
X = iris.data[:, :2]
y = iris.target


X_modified = X.copy()
X_modified[y == 0] += 2
X_modified[y == 1] -= 2





plt.scatter(X_modified[:, 0], X_modified[:, 1], c=y)
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Iris Data')
plt.show()

# Разделение данных на обучающий и тестовый наборы
X_train, X_test, y_train, y_test = train_test_split(X_modified, y, test_size=0.2, random_state=42)

X_train_scaled = X_train
X_test_scaled = X_test


slp = Perceptron()
slp.fit(X_train_scaled, y_train)
y_pred = slp.predict(X_test_scaled)


accuracy = accuracy_score(y_test, y_pred)
print(f'Accuracy: {accuracy}')

# Генетический алгоритм
population_size = 100
gene_pool = np.linspace(-1, 1, num=100)


# Функция оценки
def fitness_function(chromosome):
    print(chromosome)
    slp.coef_ = chromosome[:2].reshape(1, -1)
    slp.intercept_ = chromosome[2]
    y_pred = slp.predict(X_train_scaled)
    return accuracy_score(y_train, y_pred)


# Создание первого поколения
population = np.random.choice(gene_pool, size=(population_size, 100))

# Оценка первого поколения
fitness_scores = [fitness_function(chromosome) for chromosome in population]

# График изменения качества
best_scores = [np.max(fitness_scores)]
mean_scores = [np.mean(fitness_scores)]

# Генерация новых поколений
max_iterations = 100
for iteration in range(max_iterations):
    # Сортировка и выбор лучших особей
    sorted_indices = np.argsort(fitness_scores)[::-1]
    elite_count = int(population_size * 0.1)
    elite_population = population[sorted_indices[:elite_count]]

    # Размножение пар лучших особей
    parent_indices = np.random.choice(sorted_indices[:int(population_size * 0.5)],
                                      size=(population_size - elite_count, 2))
    parents = population[parent_indices]
    offspring = (parents[:, 0] + parents[:, 1]) / 2

    # Мутация
    mutation_mask = np.random.choice([False, True], size=offspring.shape, p=[0.95, 0.05])
    mutation = np.random.choice(gene_pool, size=offspring.shape)
    offspring = np.where(mutation_mask, offspring + mutation, offspring)

    # Обновление популяции
    population = np.concatenate((elite_population, offspring))

    # Оценка поколения
    fitness_scores = [fitness_function(chromosome) for chromosome in population]
    best_scores.append(np.max(fitness_scores))
    mean_scores.append(np.mean(fitness_scores))

# Вывод графика
plt.plot(best_scores, label='Best')
plt.plot(mean_scores, label='Mean')
plt.xlabel('Generation')
plt.ylabel('Fitness')
plt.title('Genetic Algorithm Performance')
plt.legend()
plt.show()
