#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void** createTriangularArray(int n) {
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n - i];
    }
    return (void**)arr;
}

void fillArrayWithRandomValues(void** arr, int n, int size) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            ((int**)arr)[i][j] = (int)(rand() % 100);
        }
    }
}

void* getArrayElement(void** arr, int n, int size, int x, int y) {
    if (x >= n  || y >= n &&  x < 0 || y < 0) {
        return nullptr;
    }
    if (x < y) {
        std::swap(x, y);
    }
    return &(((int**)arr)[x][y]);
}

void freeArray(void** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] ((int**)arr)[i];
    }
    delete[] arr;
}


void printArray(void** arr, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            cout << ((int**)arr)[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    string a;
    cin >> a;
    cout << a << endl;
    cout << a.size() << endl;

    return 0;
}

