#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> hashTable(7, -1);
    vector<int> nums = {86, 90, 27, 29, 38, 30, 40};
    int size = 7;

    for (int num : nums) {
        int index = num % size;
        while (hashTable[index] != -1) {
            index = (index + 1) % size;
        }
        hashTable[index] = num;
    }
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        if (hashTable[i] == -1) {
            cout << "empty";
        } else {
            cout << hashTable[i];
        }
        cout << endl;
    }

    return 0;
}
