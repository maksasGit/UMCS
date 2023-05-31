import time
import numpy as np
import matplotlib.pyplot as plt

class Data:
    def __init__(self, plik, data_set):
        self.data_set = np.array(data_set)
        self.plik = plik
        self.my_pixels = np.array([])
        self.my_expected_outputs = np.array([])

    def solve_data(self):
        data = np.loadtxt(self.plik, delimiter=',')

        all_pixels = data[:, :35]
        all_expected_outputs = data[:, 35:]

        # My set [6, 7, 11, 17, 18, 20, 21, 23, 24, 25]
        example_set = self.data_set
        for idx in example_set:
            self.my_pixels = np.append(self.my_pixels, all_pixels[idx])
            outputs = np.array([])
            for id2 in example_set:
                outputs = np.append(outputs, all_expected_outputs[idx][id2])
            self.my_expected_outputs = np.append(self.my_expected_outputs, outputs)

        self.my_pixels = self.my_pixels.reshape((-1, 35))
        self.my_expected_outputs = self.my_expected_outputs.reshape((-1, 10))

    def draw_data(self):
        for idx, pixel in enumerate(self.my_pixels):
            expected_output = self.my_expected_outputs[idx]

            print(f"Przykład {idx}:")
            print("Piksele: ", pixel)
            print("Oczekiwane wyjście: ", expected_output)
            print()

            letter_image = pixel.reshape(7, 5)
            reversed_cmap = plt.cm.get_cmap('gray_r')
            plt.imshow(letter_image, cmap=reversed_cmap)
            plt.axis('off')
            plt.show()
