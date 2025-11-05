#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getBinaryNumber() {
    string input;
    cout << "enter binary number: ";
    cin >> input;

    vector<int> num(input.length());
    for (int i = 0; i < input.length(); i++) {
        num[i] = input[i] - '0';
    }
    return num;
}

vector<int> addBinary(vector<int> a, vector<int> b) {
    int size = max(a.size(), b.size());
    vector<int> sum(size, 0);

    for (int i = 0; i < size; i++) {
        int bitA = (i < a.size()) ? a[a.size()-1-i] : 0;
        int bitB = (i < b.size()) ? b[b.size()-1-i] : 0;
        sum[size-1-i] = (bitA + bitB) % 2;
    }
    return sum;
}

vector<int> generateCarry(vector<int> a, vector<int> b) {
    int size = max(a.size(), b.size());
    vector<int> carry(size, 0);

    for (int i = 0; i < size-1; i++) {
        int bitA = (i < a.size()) ? a[a.size()-1-i] : 0;
        int bitB = (i < b.size()) ? b[b.size()-1-i] : 0;
        if (bitA + bitB >= 2) {
            carry[size-2-i] = 1;
        }
    }
    return carry;
}

vector<int> normalAddition(vector<int> a, vector<int> b) {
    int size = max(a.size(), b.size());
    vector<int> result(size, 0);
    int c = 0;

    for (int i = 0; i < size; i++) {
        int bitA = (i < a.size()) ? a[a.size()-1-i] : 0;
        int bitB = (i < b.size()) ? b[b.size()-1-i] : 0;
        int total = bitA + bitB + c;
        result[size-1-i] = total % 2;
        c = total / 2;
    }
    return result;
}

void printVector(vector<int> vec, string label) {
    cout << label << ": ";
    for (int bit : vec) {
        cout << bit << " ";
    }
    cout << endl;
}

int main() {
    cout << "first number:" << endl;
    vector<int> num1 = getBinaryNumber();
    cout << "second number:" << endl;
    vector<int> num2 = getBinaryNumber();

    cout << endl << "accelerated binary addition:" << endl;
    printVector(num1, "number 1");
    printVector(num2, "number 2");
    cout << endl;

    int step = 1;
    vector<int> sum = addBinary(num1, num2);
    vector<int> carry = generateCarry(num1, num2);

    printVector(sum, "step 1 sum");
    printVector(carry, "step 1 carry");

    while (true) {
        bool allZero = true;
        for (int bit : carry) {
            if (bit != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) break;

        step++;
        vector<int> newSum = addBinary(sum, carry);
        vector<int> newCarry = generateCarry(sum, carry);

        cout << endl;
        printVector(newSum, "step " + to_string(step) + " sum");
        printVector(newCarry, "step " + to_string(step) + " carry");

        sum = newSum;
        carry = newCarry;
    }

    cout << endl << "accelerated result: ";
    for (int bit : sum) {
        cout << bit << " ";
    }
    cout << endl;

    vector<int> normalResult = normalAddition(num1, num2);
    cout << "normal addition result: ";
    for (int bit : normalResult) {
        cout << bit << " ";
    }
    cout << endl;

    bool resultsMatch = true;
    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] != normalResult[i]) {
            resultsMatch = false;
            break;
        }
    }

    if (resultsMatch) {
        cout << "results match - correct" << endl;
    } else {
        cout << "results don't match - error" << endl;
    }

    return 0;
}