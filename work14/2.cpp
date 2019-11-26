// Кашапов Ярослав, 12вар., 100%

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void last_dir(ostream &out, istream &in, string file_out) {
    char str[255];
    char dir[255];
    while(in.getline(str, 255)) {
        int len = static_cast<int>(strlen(str));
        for(int i = len; i>=0; i--) {
            // '/' потому что я использую Linux. 
            // Пример пути Linux: /etc/ssh/sshd_config
            // Windows: C:\Windows\Temp\
            if(str[i] == '/') {
                if(i==0) {
                    out << '/' << "\n";
                    break;
                }
                int k = 0;
                for(int j=i-1; str[j] != '/'; j--, k++) {
                    dir[k] = str[j];
                }
                for(int n = k-1; n>=0; n--) {
                    out << dir[n];
                }
                out << "\n";
                break;
            }
        }
    }
    cout << "Запись в файл " << file_out << " завершена\n";
}

int main() {
    string file_out;
    string file_in;
    ofstream out;
    ifstream in;

    cout << "Введите абсолютный путь к исходному файлу:";
    cin >> file_in;
    cout << "Введите абсолютный путь к итоговому файлу";
    cin >> file_out;

    in.open(file_in);
    out.open(file_out);
    if(!in.is_open() || !out.is_open()) {
        cerr << "Ошибка создания/открытия файла";
        exit(0);
    }

    last_dir(out, in, file_out);
    return 0;
}
