#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    cout << "enter a number to factorize: ";
    cin >> number;
    // решето Эратосфена
    int x = number;
    vector<bool> prostoe(x + 1, true);
    prostoe[0] = prostoe[1] = false;
    // отмечаем составные числа
    for (int i = 2; i * i <= x; i++) {
        if (prostoe[i]) {
            for (int j = i * i; j <= x; j += i) {
                prostoe[j] = false;
            }
        }
    }
    // ыакторизация с использованием решета
    vector<int> factors;
    int temp = number;
    // перебираем только простые делители из решета
    for (int i = 2; i <= x; i++) {
        if (prostoe[i] && temp % i == 0) {
            while (temp % i == 0) {
                factors.push_back(i);
                temp /= i;
            }
        }
        if (temp == 1) break;
    }
    // выводим
    cout << "prime factors of " << number << ": ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}