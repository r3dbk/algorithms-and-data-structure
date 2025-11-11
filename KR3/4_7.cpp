#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void shakerSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
}

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

void selSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void fast_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    fast_sort(arr, left, j);
    fast_sort(arr, i, right);
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void testSort(void (*sortFunc)(int[], int), const char* name, int arr[], int n) {
    int* testArr = new int[n];
    copyArray(arr, testArr, n);

    auto start = high_resolution_clock::now();
    sortFunc(testArr, n);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << name << ": " << duration.count() << " microseconds" << endl;

    delete[] testArr;
}

void testQuickSort(int arr[], int n) {
    int* testArr = new int[n];
    copyArray(arr, testArr, n);

    auto start = high_resolution_clock::now();
    fast_sort(testArr, 0, n - 1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << "fast_sort: " << duration.count() << " microseconds" << endl;

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
    testSort(bubbleSort, "bubbleSort", small_arr, small_n);
    testSort(shakerSort, "shakerSort", small_arr, small_n);
    testSort(insSort, "insSort", small_arr, small_n);
    testSort(selSort, "selSort", small_arr, small_n);
    testSort(shellSort, "shellSort", small_arr, small_n);
    testQuickSort(small_arr, small_n);

    cout << endl;

    // большой массив
    int large_n = 10000;
    int* large_arr = new int[large_n];
    for (int i = 0; i < large_n; i++) {
        large_arr[i] = rand() % 1000;
    }

    cout << "large array " << large_n << " elements" << endl;
    testSort(bubbleSort, "bubbleSort", large_arr, large_n);
    testSort(shakerSort, "shakerSort", large_arr, large_n);
    testSort(insSort, "insSort", large_arr, large_n);
    testSort(selSort, "selSort", large_arr, large_n);
    testSort(shellSort, "shellSort", large_arr, large_n);
    testQuickSort(large_arr, large_n);

    delete[] large_arr;
    return 0;
}