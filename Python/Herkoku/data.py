import numpy as np
import matplotlib.pyplot as plt

# Wczytanie danych z pliku
data = np.loadtxt('letters.data', delimiter=',')

# Podział danych na piksele i wektory odpowiedzi
pixels = data[:, :35]
expected_outputs = data[:, 35:]

# Przykład wyświetlenia określonego zbioru
example_set = [6, 7, 11, 17, 18, 20, 21, 23, 24, 25]

for idx in example_set:
    pixel = pixels[idx]
    expected_output = expected_outputs[idx]

    print(f"Przykład {idx}:")
    print("Piksele: ", pixel)
    print("Oczekiwane wyjście: ", expected_output)
    print()

    letter_image = pixel.reshape(7, 5)
    reversed_cmap = plt.cm.get_cmap('gray_r')
    plt.imshow(letter_image, reversed_cmap)
    plt.axis('off')
    plt.show()

