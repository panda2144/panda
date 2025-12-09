#include <iostream>
#include <clocale>
using namespace std;

/// <summary>
/// Вычисляет площадь параллелограмма
/// </summary>
/// <param name="base">Длина основания</param>
/// <param name="height">Высота</param>
/// <returns>Площадь параллелограмма</returns>
/// <remarks>Если параметры некорректны, возвращает -1</remarks>
double calculateParallelogramArea(double base, double height)
{
    if (base <= 0 || height <= 0)
    {
        return -1; // некорректные параметры
    }
    return base * height;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double base = 5;
    double height = 3;
    double area = calculateParallelogramArea(base, height);
    cout << "Площадь параллелограмма: " << area << endl;
    return 0;
}