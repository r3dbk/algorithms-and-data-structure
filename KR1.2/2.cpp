#include <iostream>
#include <vector>
using namespace std;

// Алгоритмы и структуры данных КР1.2 Задание 2
// Кузнецов Святослав Владимирович ИНБО-31-25

int find_peak(const vector<int>& arr) {
    // начальный и конечный индексы
    int left = 0;
    int right = arr.size() - 1;
    // убеждаемся, что в массиве не менее 3х элементов
    if (arr.size() < 3) {
        return -1; // не является горным массивом
    }
    while (left < right) {
        int mid = left + (right - left) / 2; // средний индекс
        // проверяем, является ли mid пиком
        if (mid > 0 && mid < arr.size() - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid; // возвращаем индекс пика
        }
        
        // если левая сторона убывает, переходим на правую сторону
        if (mid > 0 && arr[mid] > arr[mid - 1]) {
            left = mid + 1;
        } else {
            right = mid; // иначе двигаемся вправо, включая mid
        }
    }
    // проверяем, найдег ли пик слева и возвращаем его индекс
    if (left > 0 && left < arr.size() - 1 && arr[left] > arr[left - 1] && arr[left] > arr[left + 1]) {
        return left;
    }
    return -1; // пик не найден, не является горным массивом
}

int main() {
    // инициализируем массив пиков
    vector<int> arr = {1, 3, 5, 4, 2};
    // находим индекс пика
    int peak_index = find_peak(arr);
    // выводим индекс пика
    if (peak_index != -1) {
        cout << "Is a mountain array, peak index is: " << peak_index << endl;
    } else {
        cout << "Is not a mountain array" << endl;
    }
}
