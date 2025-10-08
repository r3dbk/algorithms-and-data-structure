#include <iostream>
#include <vector>
using namespace std;
// Алгоритмы и структуры данных КР2 Задание 5
// Кузнецов Святослав Владимирович ИНБО-31-25

vector<int> genVonNeum() {
    vector<int> numbers;
    int count = 0;
    int n = 1;
    while (count < 10) {
        int num = n * (n + 1) / 2; // формула
        // проверяем, что число пятизначное
        if (num >= 10000 && num <= 99999) {
            numbers.push_back(num);
            count++;
        }
        n++;
    }
    return numbers;
}

int main() {
    vector<int> numbers = genVonNeum();
    // выводим
    cout << "10 five-digit von Neumann numbers:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i < numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}
