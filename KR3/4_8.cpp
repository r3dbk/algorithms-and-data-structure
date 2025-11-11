#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// обычная сортировка вставками
void insSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// улучшенная 
void binInsSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i;
        while (left < right) {
            int mid = (left + right) / 2;
            if (key < arr[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // сдвиг элементов и вставка
        for (int j = i; j > left; j--) {
            arr[j] = arr[j - 1];
        }
        arr[left] = key;
    }
}
void copyArr(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}
void testSort(void (*sortFunc)(int[], int), const char* name, int arr[], int n) {
    int* testArr = new int[n];
    copyArr(arr, testArr, n);

    auto start = high_resolution_clock::now();
    sortFunc(testArr, n);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << name << ": " << duration.count() << " microseconds" << endl;

    delete[] testArr;
}

int main() {
    srand(time(0));

    // маленький массив
    int small_n = 100;
    int small_arr[small_n];
    for (int i = 0; i < small_n; i++) {
        small_arr[i] = rand() % 100;
    }

    cout << "small array " << small_n << " elements" << endl;
    testSort(insSort, "insSort", small_arr, small_n);
    testSort(binInsSort, "binInsSort", small_arr, small_n);

    cout << endl;

    // большой массив
    int large_n = 10000;
    int* large_arr = new int[large_n];
    for (int i = 0; i < large_n; i++) {
        large_arr[i] = rand() % 1000;
    }

    cout << "large array " << large_n << " elements" << endl;
    testSort(insSort, "insSort", large_arr, large_n);
    testSort(binInsSort, "binInsSort", large_arr, large_n);

    delete[] large_arr;
    return 0;
}