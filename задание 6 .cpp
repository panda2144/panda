#include <iostream>
#include <vector>
#include <cmath>
#include <locale> // Для setlocale

class AverageCalculator {
private:
    std::vector<double> numbers; // Хранение добавленных чисел
    double sum;                  // Сумма чисел для среднего арифметического
    double product;              // Произведение чисел для среднего геометрического

public:
    // Конструктор
    AverageCalculator() : sum(0), product(1) {}

    // Добавить число
    void addNumber(double num) {
        numbers.push_back(num);
        sum += num;
        product *= num;
    }

    // Вычислить среднее арифметическое
    double getAverage() const {
        if (numbers.empty()) return 0;
        return sum / numbers.size();
    }

    // Вычислить среднее геометрическое
    double getGeometricMean() const {
        if (numbers.empty()) return 0;
        // Для отрицательных чисел или нулей, геометрическое среднее не определено
        // Можно добавить проверку или оставить как есть
        return std::pow(product, 1.0 / numbers.size());
    }

    // Очистить все данные
    void reset() {
        numbers.clear();
        sum = 0;
        product = 1;
    }
};

int main() {
    // Установка русской локализации
    setlocale(LC_ALL, "ru_RU.UTF-8");

    AverageCalculator calc;

    // Пример использования
    calc.addNumber(4);
    calc.addNumber(16);
    calc.addNumber(1);

    std::cout << "Среднее арифметическое: " << calc.getAverage() << std::endl;
    std::cout << "Среднее геометрическое: " << calc.getGeometricMean() << std::endl;

    // Очистка данных
    calc.reset();

    std::cout << "После очистки, среднее арифметическое: " << calc.getAverage() << std::endl;

    return 0;
}