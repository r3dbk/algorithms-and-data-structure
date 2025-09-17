#include <iostream>
#include <cmath>
using namespace std;

// Алгоритмыи структуры данных КР1.1
// Кузнецов Святослав Владимирович ИНБО-31-25

double f(double x) {
    // подставляем полученные корни под уравнение
    return pow(x, 5) - x - 0.2;
    }

double method(double a, double b) {
    // Проверяем что у функции разные знаки на концах, инпче выводим ошибку
    if (f(a) * f(b) >= a) {
        cerr << "На концах отрезка фкнкции одинаковые знаки" << endl;
        return NAN;
    }
    while ((b-a) / 2 > 0.0001) {
        // Находим середину
        double mid = (a+b) / 2;
        // Ищем значение функции в середине
        double mid_calc = f(mid);
        if (mid_calc == 0) {
            return mid_calc; // выходим из цикла, корень найден, возращаем егр
        } else if (f(a) * mid_calc < 0) {
            b = mid; // если щнаки разные, корень находится в левом подотрезке
        } else {
            a = mid; // иначе корень находится в правом подотрезке    
        }
        
    }
    return (a+b) / 2;
    }

int main() {
    // задаем границы отрезка
    double a = 1, b = 2;
    // записываем приблеженное значение корня, полученное из функции метод
    double root = method(a, b);
    
    cout << "Root is " << root << "\n";
}