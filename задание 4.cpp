#include <iostream>
#include <fstream>
#include <string>
#include <clocale> // для setlocale

using namespace std;

// Функция для установки цвета консоли по названию
void setConsoleColor(const string& color) {
    if (color == "red") {
        system("color 4F");
    }
    else if (color == "blue") {
        system("color 1F");
    }
    else if (color == "green") {
        system("color 2F");
    }
    else if (color == "yellow") {
        system("color 6F");
    }
    else if (color == "white") {
        system("color 7F");
    }
    else {
        system("color 0F"); // по умолчанию
    }
}

// Сохранить строку в файл
void saveToFile(const string& filename, const string& data) {
    ofstream fout(filename);
    if (fout.is_open()) {
        fout << data;
        fout.close();
    }
}

// Прочитать строку из файла
string readFromFile(const string& filename) {
    ifstream fin(filename);
    string data;
    if (fin.is_open()) {
        getline(fin, data);
        fin.close();
    }
    return data;
}

int main() {
    setlocale(LC_ALL, ""); // добавлено для поддержки локали

    // Считать любимый фильм или запросить у пользователя
    string favoriteMovie = readFromFile("favorite_movie.txt");
    if (favoriteMovie.empty()) {
        cout << "Введите ваш любимый фильм: ";
        getline(cin, favoriteMovie);
        saveToFile("favorite_movie.txt", favoriteMovie);
    }

    // Считать цвет или запросить у пользователя
    string color = readFromFile("color.txt");
    if (color.empty()) {
        cout << "Введите цвет текста (red, blue, green, yellow, white): ";
        getline(cin, color);
        saveToFile("color.txt", color);
    }

    // Установить цвет
    setConsoleColor(color);

    // Вывести любимый фильм
    cout << "Мой любимый фильм: " << favoriteMovie << endl;

    return 0;
}