#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> add(const vector<int>& a, const vector<int>& b) {
    int size = max(a.size(), b.size());
    vector<int> result(size, 0);
    int carry = 0;

    for (int i = 0; i < size; i++) {
        int digitA = (i < a.size()) ? a[a.size()-1-i] : 0;
        int digitB = (i < b.size()) ? b[b.size()-1-i] : 0;
        int sum = digitA + digitB + carry;
        result[size-1-i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result.insert(result.begin(), carry);
    }

    return result;
}

vector<int> subtract(const vector<int>& a, const vector<int>& b) {
    vector<int> result = a;
    int borrow = 0;

    for (int i = 0; i < b.size(); i++) {
        int idxA = a.size()-1-i;
        int idxB = b.size()-1-i;
        int diff = result[idxA] - b[idxB] - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[idxA] = diff;
    }

    for (int i = a.size()-b.size()-1; i >= 0 && borrow > 0; i--) {
        if (result[i] > 0) {
            result[i]--;
            borrow = 0;
        } else {
            result[i] = 9;
        }
    }

    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }

    return result;
}

vector<int> multiplySimple(const vector<int>& a, const vector<int>& b) {
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

    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }

    return result;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    if (a.size() <= 2 || b.size() <= 2) {
        return multiplySimple(a, b);
    }

    int m = min(a.size(), b.size()) / 2;

    vector<int> high1(a.begin(), a.begin() + a.size() - m);
    vector<int> low1(a.begin() + a.size() - m, a.end());
    vector<int> high2(b.begin(), b.begin() + b.size() - m);
    vector<int> low2(b.begin() + b.size() - m, b.end());

    vector<int> z0 = karatsuba(low1, low2);
    vector<int> z1 = karatsuba(add(low1, high1), add(low2, high2));
    vector<int> z2 = karatsuba(high1, high2);

    vector<int> temp = subtract(subtract(z1, z2), z0);

    vector<int> result(z2.size() + 2*m, 0);
    for (int i = 0; i < z2.size(); i++) {
        result[i] = z2[i];
    }
    for (int i = 0; i < temp.size(); i++) {
        result[i + m] += temp[i];
    }
    for (int i = 0; i < z0.size(); i++) {
        result[i + 2*m] += z0[i];
    }

    for (int i = result.size()-1; i > 0; i--) {
        if (result[i] >= 10) {
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }

    return result;
}

vector<int> getNumber() {
    string input;
    cin >> input;

    vector<int> num(input.length());
    for (int i = 0; i < input.length(); i++) {
        num[i] = input[i] - '0';
    }
    return num;
}

void printVector(const vector<int>& vec, const string& label) {
    cout << label << ": ";
    for (int digit : vec) {
        cout << digit;
    }
    cout << endl;
}

int main() {
    cout << "first number:" << endl;
    vector<int> num1 = getNumber();
    cout << "second number:" << endl;
    vector<int> num2 = getNumber();

    printVector(num1, "number 1");
    printVector(num2, "number 2");

    vector<int> resultSimple = multiplySimple(num1, num2);
    vector<int> resultKaratsuba = karatsuba(num1, num2);

    cout << endl << "column multip res: ";
    for (int digit : resultSimple) {
        cout << digit;
    }
    cout << endl;

    cout << "karatsuba res: ";
    for (int digit : resultKaratsuba) {
        cout << digit;
    }
    cout << endl;
    return 0;
}