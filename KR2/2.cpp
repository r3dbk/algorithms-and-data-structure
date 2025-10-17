#include <iostream>
#include <vector>
using namespace std;
// Алгоритмы и структуры данных КР2 Задание 2
// Кузнецов Святослав Владимирович ИНБО-31-25

int main() {
    int number;
    cout << "enter a number to factorize: ";
    cin >> number;
    if (number <= 1) {
        cout << "unable to factorize, enter a positive n > 1" << endl;
        return 0;
    }
    // решето эратосфена для проверки простоты
    vector<bool> is_prime(number + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= number; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= number; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // проверка на простоту через решето
    if (is_prime[number]) {
        cout << number << " is prime number" << endl;
        return 0;
    }
    // факторизация методом простого перебора с кратностью
    cout << "prime factors of " << number << ": ";
    int temp = number;
    bool first = true;
    for (int i = 2; i <= temp; i++) {
        if (temp % i == 0) {
            int count = 0;
            // считаем кратность множителя
            while (temp % i == 0) {
                count++;
                temp /= i;
            }
            // вывод с кратностью
            if (!first) cout << " ";
            if (count == 1) {
                cout << i;
            } else {
                cout << i << "^" << count;
            }
            first = false;
        }
    }
    cout << endl;
    return 0;
}