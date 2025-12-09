#include <iostream>
#include <clocale>
#include <stdexcept>

void printRecursive(int n) {
    if (n > 10) return;
    std::cout << n << std::endl;
    printRecursive(n + 1);
}

int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Установите точку останова на этой строке (цикл)
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << std::endl;
    }

    std::cout << "Рекурсивный вызов:" << std::endl;
    printRecursive(1);

    // Пример деления с обработкой исключения
    try {
        int a = 10;
        int b = 0; // деление на ноль
        if (b == 0) {
            throw std::runtime_error("Деление на ноль!");
        }
        int result = a / b;
        std::cout << "Результат: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}