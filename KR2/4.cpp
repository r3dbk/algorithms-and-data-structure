#include <iostream>
using namespace std;
// Алгоритмы и структуры данных КР2 Задание 4
// Кузнецов Святослав Владимирович ИНБО-31-25

// ф-я умножения по модулю
long long modMul(long long a, long long b, long long mod) {
    return (a * b) % mod;
}

// тест Лукаса-лемера
bool lucasLehmer(int p) {
    long long m = (1LL << p) - 1; // 2^p - 1
    long long s = 4;
    for (int i = 0; i < p - 2; i++) {
        s = (modMul(s, s, m) - 2 + m) % m;
    }
    return s == 0;
}

// проверка простоты p
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int p;
    cin >> p;
    if (!isPrime(p)) {
        cout << "Invalid input: p must be prime" << endl;
        return 1;
    }
    long long mersenne = (1LL << p) - 1;
    if (lucasLehmer(p)) {
        cout << mersenne << " is prime" << endl;
    } else {
        cout << mersenne << " is composite" << endl;
    }
    return 0;
}
