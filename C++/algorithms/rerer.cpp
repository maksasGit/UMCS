#include<iostream>
#include<fstream>
#include<string>

using namespace std;


bool fun_1(unsigned short arr[], int size_arr){  // постоянно ли увел массив
    for (int i = 1; i < size_arr; i++) {
        if (arr[i] < arr[i - 1]) return false;  // если предидущий элемент больше текущего, то ЛОЖЬ
    }
    return true;            // если все ОК
}


bool fun_2(unsigned short arr[], int size_arr){     // все ли элементы с 0 на четных позициях в битовом представлении
    for (int i = 0; i < size_arr; i++) {            // перебираем все элементы
        int x = arr[i];                             // для удобства
        for (int j = 0; j < 32; j++) {              // перебираем бит
            if ((j%2)== 0 && ((1<<j)&x)==(1<<j)) {  // если бит четный и 1, то ЛОЖЬ
                return false;
            }
        }
    }
    return true;    // если все ОК
}

unsigned short * find_subset(unsigned short arr[] , int size_arr , bool (*fun)(unsigned short arr[], int size_arr)){
    for (int i = size_arr; i >= 1; i--) {       //  перебираем размер с большего. Так как ищем максимум
        unsigned short test[i];                 // создаем массив для передачи в функцию
        for (int j = 0; j <= size_arr - i; j++) {   // перебераем начало
            for (int c = j; c < j + i; c++) {       // перебираем от начала + размер
                test[c - j] = arr[c];               // перезаписываем массив ТЕСТ
            }
            if (fun(test , i)) {                // вызываем функцию
                    return &arr[j];                // если ОК, возвращаем указатель на начло подмассива
            }
        }
    }
}


int main() {
    unsigned short arr[5] = {1 , 2 , 1 , 2 , 3};        // тест
    find_subset(arr , 5 , fun_2);
    return 0;
}
