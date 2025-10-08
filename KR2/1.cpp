#include <iostream>
#include <vector>
using namespace std;
// Алгоритмы и структуры данных КР2 Задание 1
// Кузнецов Святослав Владимирович ИНБО-31-25

int gcdByDivision(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcdBySubtraction(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    vector<int> numbers;
    int num;
    cout << "Enter numbers:" << endl;
    // Читаем числа в цикле
    for (int i = 0; i < 4; i++) {
        cin >> num;
        numbers.push_back(num);
        if (numbers.size() == 3) {
            if (cin.peek() == '\n') {
                break;
            }
        }
    }
    // автоматически определяем метод на основе количества чисел
    if (numbers.size() == 3) {
        // Метод деления для трех чисел
        int gcd = numbers[0];
        for (int i = 1; i < 3; i++) {
            gcd = gcdByDivision(gcd, numbers[i]);
        }
        cout << "GCD division method: " << gcd << endl;
    } else {
        // Метод вычитания для четырех чисел
        int gcd = numbers[0];
        for (int i = 1; i < 4; i++) {
            gcd = gcdBySubtraction(gcd, numbers[i]);
        }
        cout << "GCD subtraction method: " << gcd << endl;
    }
    return 0;
}