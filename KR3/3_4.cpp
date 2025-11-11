#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getNumber() {
    string input;
    cin >> input;

    vector<int> num(input.length());
    for (int i = 0; i < input.length(); i++) {
        num[i] = input[i] - '0';
    }
    return num;
}

vector<int> multiplyDecimal(vector<int> a, vector<int> b) {
    int size = a.size() + b.size();
    vector<int> result(size, 0);

    for (int i = b.size()-1; i >= 0; i--) {
        for (int j = a.size()-1; j >= 0; j--) {
            int pos = i + j + 1;
            result[pos] += a[j] * b[i];
        }
    }

    for (int i = size-1; i > 0; i--) {
        if (result[i] >= 10) {
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    return result;
}

void printVector(vector<int> vec, string label) {
    cout << label << ": ";
    for (int bit : vec) {
        cout << bit;
    }
    cout << endl;
}

int main() {
    cout << "first number:" << endl;
    vector<int> num1 = getNumber();
    cout << "second number:" << endl;
    vector<int> num2 = getNumber();

    cout << endl << "decimal multiplication:" << endl;
    printVector(num1, "number 1");
    printVector(num2, "number 2");

    vector<int> result = multiplyDecimal(num1, num2);

    int start = 0;
    while (start < result.size() && result[start] == 0) {
        start++;
    }

    cout << "multiplication result: ";
    if (start == result.size()) {
        cout << "0";
    } else {
        for (int i = start; i < result.size(); i++) {
            cout << result[i];
        }
    }
    cout << endl;

    return 0;
}