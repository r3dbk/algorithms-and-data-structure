#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isFirstNumBigger(const string& num1, const string& num2) {
    if (num1.length() != num2.length()) {
        return num1.length() > num2.length();
    }
    return num1 > num2;
}

string addLargeNums(const string& num1, const string& num2) {
    string result = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';

        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string subtrLargeNums(const string& num1, const string& num2) {
    string result = "";
    int borrow = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0) {
        int digit1 = num1[i--] - '0';
        int digit2 = j >= 0 ? num2[j--] - '0' : 0;

        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back((digit1 - digit2) + '0');
    }
    // удаляем ведущие нули
    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    char operation;
    cout << "large number calculator" << endl;
    cout << "---" << endl;
    // ввод 1го числа с проверкой
    while (true) {
        cout << "Enter first: ";
        cin >> num1;
        // проверка что число >= 1 и состоат из цифр
        bool valid = true;
        for (char c : num1) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
        if (valid && num1.length() > 0 && !(num1.length() == 1 && num1[0] == '0')) {
            break;
        }
        cout << "Num must be >= 1 and contain only digits" << endl;
    }
    // ввод 2го числа с пров-й
    while (true) {
        cout << "Enter second: ";
        cin >> num2;
        bool valid = true;
        for (char c : num2) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
        if (valid && num2.length() > 0 && !(num2.length() == 1 && num2[0] == '0')) {
            break;
        }
        cout << "Num must be >= 1 and contain only digits" << endl;
    }
    // ввод операции
    cout << "enter operation (+ or -): ";
    cin >> operation;
    string result;
    if (operation == '+') {
        result = addLargeNums(num1, num2);
        cout << result << endl;
    }
    else if (operation == '-') {
        if (isFirstNumBigger(num1, num2)) {
            result = subtrLargeNums(num1, num2);
            cout << result << endl;
        } else {
            result = subtrLargeNums(num2, num1);
            cout << "-" << result << endl;
        }
    }
    else {
        cout << "invalid operation, only + and -" << endl;
        return 1;
    }
    return 0;
}