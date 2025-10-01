#include <iostream>
using namespace std;

int main() {
    int x, y, result;
    // запрос чисел для поиска НОД
    cout << "enter 2 numbers for GCD: " << endl;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);
    bool flag = false;
    // поиск НОДа методом деления
    while (flag == false) {
        if (x % y == 0) {
            result = y;
            flag = true;
        }
        else {
            if (x == 0 || y == 0) {
                result = 1;
                flag = true;
            }
            x = y;
            y = x % y;
        }
    }
    // вывод результата
    cout << "result: " << result << endl;
    return 0;
}
