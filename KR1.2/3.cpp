#include <iostream>
#include <vector>
using namespace std;

// Алгоритмы и структуры данных КР1.2 Задание 3
// Кузнецов Святослав Владимирович ИНБО-31-25

void count_pos_neg(const vector<int>& arr) {
    // используем бинарный поиск для нахожления первого положительного числа
    int left = 0;
    int right = arr.size() - 1;
    int first_positive_index = arr.size(); // предположим что положительных нет

    while (left <= right) {
        int mid = left + (right - left) / 2;
        // если нашли положительное число, сохраняем индекс первого положительного
        if (arr[mid] > 0) {
            first_positive_index = mid;
            right = mid - 1; // продолжаем искать в левой части
        } else {
            left = mid + 1; // иначе ищем в правой
        }
    }
    // кол-во + чисел
    int positive_count = arr.size() - first_positive_index;
    // кол-во - чисел
    int negative_count = first_positive_index;
    // сравниваем кол-во положительных чисел и отрицательных
    if (positive_count > negative_count) {
        cout << "There are more positive numbers: " << positive_count << endl;
    } else if (negative_count > positive_count) {
        cout << "There are more negative numbers: " << negative_count << endl;
    } else {
        cout << "Number of positive and negative numbers is equal" << endl;
    }
}

int main() {
    vector<int> arr = {-5, -3, -1, 0, 1, 2, 3, 4, 5};
    // вызываем функцию для подсчета положительных и отрицательных чисел
    count_pos_neg(arr);
}
