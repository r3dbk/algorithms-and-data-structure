#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
// Алгоритмы и структуры данных КР2 Задание 3
// Кузнецов Святослав Владимирович ИНБО-31-25

void fermat_factorization(int n, map<int, int>& factors, const vector<bool>& sieve) {
    if (n == 1) return;
    // проверка простоты
    if (n < sieve.size() && sieve[n]) {
        factors[n]++;
        return;
    }
    /* метод Ферма:
       n = x² - y² = (x+y)(x-y) */
    int x = ceil(sqrt(n));
    int y2 = x * x - n;
    // полный квадрат
    while (true) {
        int y = sqrt(y2);
        if (y * y == y2) break;
        x++;
        y2 = x * x - n;
    }
    int a = x + sqrt(y2);
    int b = x - sqrt(y2);
    // рекурсивная факторизация
    fermat_factorization(a, factors, sieve);
    fermat_factorization(b, factors, sieve);
}

int main() {
    int number;
    cout << "enter a number to factorize: ";
    cin >> number;

    // проверка на единицу/ноль/отриц. число из-за использ-ия решета
    if (number <= 1) {
        cout << "unable to factorize, enter a positive n > 1" << endl;
        return 0;
    }
    // проверка на четность
    if (number % 2 == 0) {
        cout << "Number must be odd and composite" << endl;
        return 0;
    }
    // решето Эратосфена
    vector<bool> is_prime(number + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= number; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= number; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // проверка на простоту
    if (is_prime[number]) {
        cout << "Number must be composite" << endl;
        return 0;
    }
    // факторизация методом Ферма
    map<int, int> factors;
    fermat_factorization(number, factors, is_prime);
    // вывод
    cout << "prime factors of " << number << ": ";
    bool first = true;
    for (auto& [factor, count] : factors) {
        if (!first) cout << " ";
        cout << factor;
        if (count > 1) cout << "^" << count;
        first = false;
    }
    cout << endl;
    return 0;
}