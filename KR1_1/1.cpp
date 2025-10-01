#include <iostream>
#include <cmath>
using namespace std;

// Алгоритмы и структуры данных КР1.1 Задание 1
// Кузнецов Святослав Владимирович ИНБО-31-25
// Метод половинного деления

double f(double x) {
    // подставляем полученные корни под уравнение
    return pow(x, 5) - x - 0.2;
    }

double method(double a, double b) {
   // проверка, что функция имеет разные знаки на начальных точках
    if (f(a) * f(b) >= a) {
        cerr << "На концах отрезка функции одинаковые знаки" << endl;
        return NAN;
    }
    while ((b-a) / 2 > 0.0001) {
        // Находим середину
        double mid = (a+b) / 2;
        // Ищем значение функции в середине
        double mid_calc = f(mid);
        if (mid_calc == 0) {
            return mid_calc; // выходим из цикла, корень найден, возращаем его
        } else if (f(a) * mid_calc < 0) {
            b = mid; // если знаки разные, корень находится в левом подотрезке
        } else {
            a = mid; // иначе корень находится в правом подотрезке    
        }
        
    }
    return (a+b) / 2;
}

int main() {
    // задаем границы отрезка
    double a = 1, b = 2;
    // записываем приближённое значение корня, полученное из функции "method"
    double root = method(a, b);
    // результат подстановки найденного корня в уравнение (в идеале околонулевое значение)
    double eq_res = f(root);
    
    cout << "Root is " << root << endl;
    cout << "Equation result is " << eq_res << endl;
}

// Результат выполнения:

// Root is 1.04474
// Equation result is -0.000113664