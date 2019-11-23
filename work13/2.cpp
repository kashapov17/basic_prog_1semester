// Кашапов Ярослав, 12вар., 100%

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define FILE_NAME "work13.txt"

int **make2d(size_t size) {
    int **arr;
    arr = new int*[size];
    for(size_t i=0; i<size; i++) {
        arr[i] = new int[size];
        for(size_t j=0; j<size; j++) {
            // если выше побочной диагонали:
            if(i<size-1 && j<size-i-1) {
                arr[i][j] = 0;
            }
            // если ниже побочной диагонали:
            else if(i>0 && j>=size-i) {
                arr[i][j] = 2;
            }
            // если ни то, ни другое, т.е. сама побочная диагональ
            else arr[i][j] = 1;
        }
    }
    return arr;
}

void fwrite(int *const *arr, size_t size, ostream &fout) {
    for(size_t i=0; i<size; i++) {
        for(size_t j=0; j<size; j++) {
            fout << arr[i][j] << " ";
        }
        fout << "\n";
    }
    cout << "\nЗапись в файл " << FILE_NAME << " завершена\n\n";
}

void fread(string file_name) {
    ifstream fin;
    string line;
    fin.open(file_name);
    if(!fin.is_open()) {
        cerr << "Ошибка открытия файла\n";
        exit(0);
    }
    cout << "Содержимое файла:\n";
    while(getline(fin, line)) {
        cout << line << "\n";
    }
    fin.close();
    cout << "\nЧтение из файла завершено\n";
}

int main() {
    int **arr;
    size_t n;
    ofstream fout;

    fout.open(FILE_NAME);
    if(!fout.is_open()) {
        cerr <<  "Ошибка открытия файла\n";
        exit(0);
    }
    cout << "Введите размерность матрицы N x N; N = ";
    cin >> n;
    arr = make2d(n);
    fwrite(arr, n, fout);
    fout.close();
    fread(FILE_NAME);
    return 0;
}
