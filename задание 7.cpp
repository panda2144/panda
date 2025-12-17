#include <iostream>
#include <cassert>

struct AreaCalculator {
    // Определяем свою константу π
    static constexpr double PI = 3.14159265358979323846;

    // Площадь треугольника: основание * высота / 2
    static double triangleArea(double base, double height) {
        return 0.5 * base * height;
    }

    // Площадь прямоугольника: width * height
    static double rectangleArea(double width, double height) {
        return width * height;
    }

    // Площадь круга: pi * r^2
    static double circleArea(double radius) {
        return PI * radius * radius;
    }

    // Площадь трапеции: (a + b) / 2 * height
    static double trapezoidArea(double base1, double base2, double height) {
        return 0.5 * (base1 + base2) * height;
    }
};

// Пример использования и простые тесты
int main() {
    // Положительные тесты (ожидаемо корректные значения)
    // 1) треугольник: основание 5, высота 4 -> 10
    double tBase = 5.0, tHeight = 4.0;
    assert(AreaCalculator::triangleArea(tBase, tHeight) == 10.0);

    // 2) прямоугольник: ширина 6, высота 3 -> 18
    double rectW = 6.0, rectH = 3.0;
    assert(AreaCalculator::rectangleArea(rectW, rectH) == 18.0);

    // Отрицательные тесты (ожидаемая ложь: некорректные сравнения)
    // 1) Проверяем, что площадь круга радиуса 2.0 не равна 15 (π*4 ≈ 12.566...)
    double r = 2.0;
    double circleAreaValue = AreaCalculator::circleArea(r);
    assert(circleAreaValue != 15.0);

    // 2) Площадь трапеции с основаниями 4 и 7 и высотой 5 -> 0.5*(4+7)*5 = 27.5
    double b1 = 4.0, b2 = 7.0, tHeight2 = 5.0;
    double trapezoidAreaValue = AreaCalculator::trapezoidArea(b1, b2, tHeight2);
    // неверное предположение для теста
    assert(trapezoidAreaValue != 30.0);

    // Дополнительные проверки корректности реальных значений (необязательно, но полезно)
    std::cout << "Triangle area (5,4) = " << AreaCalculator::triangleArea(tBase, tHeight) << "\n";
    std::cout << "Rectangle area (6,3) = " << AreaCalculator::rectangleArea(rectW, rectH) << "\n";
    std::cout << "Circle area (2) = " << circleAreaValue << "\n";
    std::cout << "Trapezoid area (4,7,5) = " << trapezoidAreaValue << "\n";

    std::cout << "All tests passed (assertions succeeded)." << std::endl;
    return 0;
}