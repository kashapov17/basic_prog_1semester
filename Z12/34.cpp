#include <iostream>
#include <fstream>
using namespace std;

#define FILE_NAME "z12_1.txt"

int **make2d(size_t nrows, size_t ncols) {
    srand(time(NULL));
    int **arr;
    arr = new int*[nrows];
    for(size_t k=0; k<nrows; k++) {
        arr[k] = new int[ncols];
    }
    for(size_t i=0; i<nrows; i++) {
        for(size_t j=0; j<ncols; j++) {
            arr[i][j] = rand()%10;
        }
    }
    return arr;
}

void print2d(const int *const *arr, size_t nrows, size_t ncols, ofstream &ost) {
    for(size_t i=0; i<nrows; i++) {
        for(size_t j=0; j<ncols; j++) {
            ost << arr[i][j] << " ";
        }
        ost << "\n";
    }
    cout << "\nЗапись в файл " << FILE_NAME << " завершена\n\n";
}

int main() {
    size_t ncols, nrows;
    int **arr;
    ofstream ost;

    ost.open(FILE_NAME);
    if(!ost.is_open()) {
        cerr << "Ошибка открытия файла\n";
        exit(0);
    }

    cout << "nrows = ";
    cin >> nrows;
    cout << "ncols = ";
    cin >> ncols;

    arr = make2d(nrows, ncols);
    print2d(arr, nrows, ncols, ost);
    ost.close();
    return 0;
}
