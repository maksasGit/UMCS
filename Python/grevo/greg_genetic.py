class Genetics:
    def __init__(self):
        self.elite_percent = 0.1 # procent najlepszych do nowego pokolenia
        self.parent_percent = 0.5 # procen losujących par

    def fit(self, tests, answers, population_size=500, iterations=500):
        self.tests = tests
        self.answers = answers
        self.population_size = population_size
        # формула вычесляет количество хромосом относительно входных и выходных данных
        self.gen_size = len(answers[0]) * len(tests[0]) + len(answers[0])
        self.iterations = iterations
        # гены для мутации в диапозоне от -1 до 1 с шагом 0.02
        # решил их исползовать так как такой точности вплоне достаточно для
        # правильной активации и их не так много, чтобы мутация была эффективной
        self.possible_genes = np.linspace(-1, 1, num=101)
        # создаю популяцию случайным способом используя случайные гены
        self.population = np.random.choice(self.possible_genes, size=(self.population_size, self.gen_size))


        # для графика
        best = []
        avg = []

        for iteration in range(self.iterations):
            results = self.selection()
            best.append(np.max(results))
            avg.append(np.mean(results))
            if self.evaluation(self.population[0]) == 1.0:
                break  # если лучший представитель достиг максимльно результата


        plt.plot(best, label='Najlepsze')
        plt.plot(avg, label='Średnie')
        plt.xlabel('Generacja')
        plt.ylabel('Dopasowanie')
        plt.title('Wydajność algorytmu genetycznego')
        plt.legend()
        plt.show()

    def evaluation(self, chromosome):
        # перевожу одномерный массив с хромосомами представителя в матрицы
        weights = chromosome[:self.gen_size - len(self.answers[0])].reshape(len(self.answers[0]), len(self.tests[0]))
        biases = chromosome[self.gen_size - len(self.answers[0]):].reshape(len(self.answers[0]))
        accuracy = 0
        for i in range(len(self.tests)):
            # вычесляю значения нейронов
            activations = np.dot(weights, self.tests[i].reshape(len(self.tests[0]))) + biases
            predictions = np.where(activations >= 0.0, 1, -1)
            # проверяю с ожидаемым ответом
            for item, expected in zip(predictions, self.answers[i]):
                if item == expected:
                    accuracy += 1
        # возвращаю точность представителя
        # делю все его правильные ответы на количество вопросов умноженое на количество ответов в тесте
        # для того чтобы его точность была в диапозоне от 0 до 1 (мне так удобнее смотреть на графике)
        return accuracy / (len(self.tests) * len(predictions))

    def selection(self):
        # получаю номера лучших представителей
        evaluations = [self.evaluation(chromosome) for chromosome in self.population]
        sorted_population = np.argsort(evaluations)[::-1] # переворчиваю массив
        self.population = self.population[sorted_population] # сортирую основной массив
        elite_population = self.population[:int(self.population_size * self.elite_percent)] # выбераю лучшие 10% от всей популяции
        new_population = []
        for _ in range(int(self.population_size - len(elite_population))): # остальных получаю скрещеиванием
            parents_id = np.random.choice(int(self.population_size * self.parent_percent), 2, replace=False)
            # выбираю номера 2 родителй
            parent1, parent2 = self.population[parents_id[0]], self.population[parents_id[1]]
            new_element = []
            random_choices = np.random.choice([0, 1, 2], size=self.gen_size, p=[0.1, 0.45, 0.45])
            for i, choice in enumerate(random_choices):
                if choice == 0:
                    gene = np.random.choice(self.possible_genes)
                elif choice == 1:
                    gene = parent1[i]
                else:
                    gene = parent2[i]
            new_element.append(gene)
            new_population.append(new_element)
        self.population = np.concatenate((elite_population, new_population))
        return evaluations

    def predict(self, X):
      weights = self.population[0][:self.gen_size - len(self.answers[0])].reshape(len(self.answers[0]), len(self.tests[0]))
      biases = self.population[0][self.gen_size - len(self.answers[0]):].reshape(len(self.answers[0]))
      all_predictions = []
      for i in range(len(X)):
            activations = np.dot(weights, X[i].reshape(len(X[0]))) + biases
            predictions = np.where(activations >= 0.0, 1, -1)
            all_predictions.append(predictions)
      return all_predictions


    def missclassified(self, X, y):
        print(self.population[0])
        weights = self.population[0][:self.gen_size - len(self.answers[0])].reshape(len(self.answers[0]), len(self.tests[0]))
        biases = self.population[0][self.gen_size - len(self.answers[0]):].reshape(len(self.answers[0]))
        global_accuracy = 0
        for i in range(len(X)):
            activations = np.dot(weights, X[i].reshape(len(X[0]))) + biases
            predictions = np.where(activations >= 0.0, 1, -1)
            accuracy = 0
            print(y[i], " -- ", predictions, end="")
            for item, expected in zip(predictions, y[i]):
                if item == expected:
                    accuracy += 1
            if accuracy != len(self.answers[0]):
                print(" : ", accuracy, " (BŁĄD) ")
            else:
                print(" : ", accuracy)
            global_accuracy += accuracy / len(predictions)
        return global_accuracy / len(self.tests)
