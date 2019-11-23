#include <iostream>
#include <fstream>
using namespace std;

#define FILE_NAME "z12_3.txt"

int **make2d(size_t size) {
    int **arr;
    arr = new int*[size];
    for(size_t k=0; k<size; k++) {
        arr[k] = new int[size];
    }
    for(size_t i=0; i<size; i++) {
        for(size_t j=0; j<size; j++) {
            cout << "элемент " << i+1 << "," << j+1 << " = ";
            cin >> arr[i][j];
        }
    }
    return arr;
}

void transponse(int **arr, size_t size) {
    for(size_t i=0; i<size; i++) {
        for(size_t j=0; j<i; j++) {
            swap(arr[j][i], arr[i][j]);
        }
    }
}

void print_transposed(const int *const *arr, size_t size, ostream &ost) {
    for(size_t i=0; i<size; i++) {
        for(size_t j=0; j<size; j++) {
            ost << arr[i][j] << " ";
        }
        ost << "\n";
    }
    cout << "\nЗапись в файл " << FILE_NAME << " завершена\n\n";
}

int main() {
    size_t size;
    int **arr;
    ofstream ost;

    ost.open(FILE_NAME);
    if(!ost.is_open()) {
        cerr << "Ошибка открытия файла";
        exit(0);
    }
    cout << "Введите порядок матрицы: ";
    cin >> size;

    arr = make2d(size);
    transponse(arr, size);
    print_transposed(arr, size, ost);
    ost.close();
    return 0;
}
