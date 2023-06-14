import numpy as np
from matplotlib import pyplot as plt
from sklearn.metrics import accuracy_score


best = []
avg = []

class Eugenics:
    def __init__(self):
        self.elite_procent = 0.1
        self.parent_procent = 0.5

    def start_train(self, tests, answers, population_size=100, iterations=200):
        self.tests = tests
        self.answers = answers
        self.population_size = population_size
        self.gen_size = len(answers[0]) * len(tests[0]) + len(answers[0])
        self.iterations = iterations
        self.init_create()

        for iter in range(self.iterations):
            results = self.selection()
            best.append(np.max(results))
            avg.append(np.mean(results))
            print("Iteration №", iter)
            print("Max: ", np.max(results))
            print("Average: ", np.mean(results))

        sorted_population = np.argsort([self.evaluation(chromosome) for chromosome in self.population])[::-1]
        for spicemen in self.population[sorted_population]:
            print(spicemen, " - ", self.evaluation(spicemen))

        plt.plot(best, label='Best')
        plt.plot(avg, label='Mean')
        plt.xlabel('Generation')
        plt.ylabel('Fitness')
        plt.title('Genetic Algorithm Performance')
        plt.legend()
        plt.show()

    def init_create(self):
        self.possible_gens = np.linspace(-1, 1, num=100)
        self.population = np.random.choice(self.possible_gens, size=(self.population_size, self.gen_size))

    def evaluation(self, chromosome):
        weights = chromosome[:self.gen_size - 3].reshape(3,2)
        biases = chromosome[self.gen_size - 3:]
        global_accuracy = 0
        for i in range(len(self.tests)):
            activations = np.dot(weights, self.tests[i].reshape(-1, 1)) + biases
            print(".",activations)
            predictions = np.where(activations >= 0, 1, -1)
            accuracy = 0
            print("!", predictions)
            print("?", self.answers[i])
            for item, expected in zip(predictions, self.answers[i]):
                print(item, " - ", expected)
                if (item == expected).all():
                    accuracy += 1
            print(accuracy)
            global_accuracy += accuracy / len(predictions)
        return global_accuracy / len(self.tests)

    def selection(self):
        sorted_population = np.argsort([self.evaluation(chromosome) for chromosome in self.population])[::-1]
        self.population = self.population[sorted_population]
        elite_population = self.population[:int(self.population_size*self.elite_procent)]
        new_populataion = []
        for iter in range(int(self.population_size-len(elite_population))):
            parents_id = np.random.choice(int(self.population_size * self.parent_procent), 2 , replace=False)
            parent1, parent2 = self.population[parents_id[0]], self.population[parents_id[1]]
            new_element = []
            for i in range(self.gen_size):
                rand = np.random.rand()
                if rand > 0.9:
                    new_element.append(np.round(np.random.uniform(-1, 1), 2))
                elif rand > 0.45:
                    new_element.append(parent1[i])
                else:
                    new_element.append(parent2[i])
            new_populataion.append(new_element)
        self.population = np.concatenate((elite_population , new_populataion))
        return [self.evaluation(chromosome) for chromosome in self.population]

