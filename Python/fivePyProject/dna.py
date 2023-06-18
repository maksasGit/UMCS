import csv
import time
import csv

import numpy as np

char_to_num = {'A': 1, 'T': 3, 'C': 2, 'G': 4}

def read_csv_file(file_path):
    data_array = []
    with open(file_path, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            data_row = [char_to_num.get(it, -1) for it in row[0]]
            data_array.append(data_row)
    return data_array


file_path = "data/primers.txt"
data_array = read_csv_file(file_path)

count = len(data_array)
len_primer = 20
def comparer(primer1, primer2):
    global_max = 0
    for i in range(39):
        if (40 - i < global_max):
            break
        ans = np.sum(primer1 , primer2)
        print(ans)
    return global_max



s = 0
for i in range(1):
    start_t = time.time()
    primer_1 = data_array[i]
    for j in range(count-i):
        primer_2 = data_array[i+j]
        s += comparer(primer_1, primer_2)
    end_t = time.time()
    print(i, "\t", end_t - start_t)
    print(s)

