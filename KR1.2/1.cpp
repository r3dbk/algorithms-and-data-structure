#include <iostream>
#include <vector>
using namespace std;

// Алгоритмыи структуры данных КР1.2 Задание 1
// Кузнецов Святослав Владимирович ИНБО-31-25

int bin_search(const vector<int>& arr, int target) {
    // начало и конец диапазона
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // средний индекс

        // проверка, равен ли элемент в середине искомому значениюб
        if (arr[mid] == target) {
            return mid; // возвращаем индекс найденного элемента
        }
        // если целевой элемент больше, игнорируем левую половину
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // иначе игнорируем правую половину
        else {
            right = mid - 1;
        }
    }

    // если элемент не найден, возвращаем позицию для вставки
    return left; // left указывает на первую позицию, где можно вставить элемент
}

// функция вставки элемента в массив
void ins_element(vector<int>& arr, int position, int element) {
    arr.insert(arr.begin() + position, element); // вставляем элемент в необходимую позицию
}
int main() {
    // инициализация отсортированного массива
    vector<int> arr = {1, 3, 5, 7, 9};
    // запрпшиваем у пользователя целевое значение для поиска
    int target;
    cout << "Enter needed element: ";
    cin >> target;
    
    // выполняем бинарный поиск и проверяем результат
    int position = bin_search(arr, target);
    if (position < arr.size() && arr[position] == target) {
        cout << "Element " << target << " is found on position " << position << endl;
    } else {
        cout << "Element " << target << " is not found" << endl;
        cout << "You can insert element on position " << position << endl;

        // вставляем элемент
        ins_element(arr, position, target);
        cout << "Ready array: ";
        
        // выводим обновленный массив
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}
