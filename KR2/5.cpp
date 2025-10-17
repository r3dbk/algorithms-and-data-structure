#include <iostream>
#include <vector>
using namespace std;

vector<int> genVonNeum() {
    vector<int> numbers;
    int seed = 12345;
    for (int i = 0; i < 10; i++) {
        numbers.push_back(seed);
        long long square = (long long)seed * seed;
        square /= 100;
        seed = square % 100000;
    }
    return numbers;
}

int main() {
    vector<int> numbers = genVonNeum();
    cout << "10 von Neumann numbers:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i < numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}