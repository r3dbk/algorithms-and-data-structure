#include <iostream>
#include <vector>
using namespace std;

vector<int> addBinary(vector<int> a, vector<int> b) {
    vector<int> sum(a.size(), 0);
    for (int i = a.size() - 1; i >= 0; i--) {
        int bitSum = a[i] + b[i];
        sum[i] = bitSum % 2;
    }
    return sum;
}

vector<int> generateCarry(vector<int> a, vector<int> b) {
    vector<int> carry(a.size(), 0);
    for (int i = a.size() - 1; i > 0; i--) {
        if (a[i] + b[i] >= 2) {
            carry[i-1] = 1;
        }
    }
    return carry;
}

vector<int> normalAddition(vector<int> a, vector<int> b) {
    vector<int> result(a.size(), 0);
    int c = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int total = a[i] + b[i] + c;
        result[i] = total % 2;
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
    vector<int> num1 = {0,1,0,0,0,1,1,1,0,0};
    vector<int> num2 = {0,1,0,1,1,1,0,1,1,1};

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