#include <iostream>
#include <vector>
using namespace std;
// Алгоритмы и структуры данных КР2 Задание 1
// Кузнецов Святослав Владимирович ИНБО-31-25

int gcdByDiv(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = abs(temp);
    }
    return a;
}

int main() {
    vector<int> numbers;
    int num;
    cout << "Enter 3 numbers:" << endl;
    for (int i = 0; i < 4; i++) {
        if (!(cin >> num)) {
            if (cin.eof()) break;
            cout << "Enter positive integer only" << endl;
            return 1;
        }
        numbers.push_back(num);
        // проверка на лишние числа
        if (numbers.size() == 3) {
            if (cin.peek() != '\n' && cin.peek() != EOF) {
                cout << "Enter exactly 3 numbers" << endl;
                return 1;
            }
            break;
        }
    }
    // проверка на все нули
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

    if (sum == 0) {
        cout << "GCD is: n >= 1" << endl;
        return 0;
    }
    // вычисляем
    int gcd = numbers[0];
    for (int i = 1; i < 3; i++) {
        gcd = gcdByDiv(gcd, numbers[i]);
    }
    // вывод
    cout << "GCD division method: " << gcd << endl;

    return 0;
}