#include <iostream>
#include <cmath>
using namespace std;
// Алгоритмы и структуры данных КР2 Задание 3
// Кузнецов Святослав Владимирович ИНБО-31-25

void factRecurs(int n) {
    // проверка на простоту
    bool prime = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }
    if (prime) {
        cout << n;
        return;
    }
    // сам мнтод Ферма
    int x = ceil(sqrt(n));
    for (int i = 0; i < 1000; i++) {
        long long temp = (long long) x * x - n;
        if (temp >= 0) {
            int y = sqrt(temp);
            if ((long long) y * y == temp) {
                int a = x + y;
                int b = x - y;

                if (a != n && b != 1) {
                    cout << "(";
                    factRecurs(a);
                    cout << "*";
                    factRecurs(b);
                    cout << ")";
                    return;
                }
            }
        }
        x++;
    }
    // простой перебор
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << "(";
            factRecurs(i);
            cout << "*";
            factRecurs(n / i);
            cout << ")";
            return;
        }
    }
}

int main() {
    // инициализируем переменнуб и принимаем от пользователя число
    int number;
    cin >> number;
    if (number < 2) {
        return 1;
    }
    factRecurs(number);
    cout << endl;
    return 0;
}
