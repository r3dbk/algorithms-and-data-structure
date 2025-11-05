#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// выравнивание длтны чисел с пом. добавления ведущих нулей
string alignLength(const string& num, int length) {
    if (num.length() >= length) return num;
    return string(length - num.length(), '0') + num;
}

// вычисление промежуточной суммы
string calculateIntermediateSum(const string& num1, const string& num2) {
    string result = "";
    int length = max(num1.length(), num2.length());
    string alignedNum1 = alignLength(num1, length);
    string alignedNum2 = alignLength(num2, length);
    for (int i = 0; i < length; i++) {
        int bit1 = alignedNum1[i] - '0';
        int bit2 = alignedNum2[i] - '0';
        result += (bit1 == bit2) ? '0' : '1';
    }
    return result;
}

// вычисление числа переносов
string calculateCarry(const string& num1, const string& num2) {
    string result = "0";
    int length = max(num1.length(), num2.length());
    string alignedNum1 = alignLength(num1, length);
    string alignedNum2 = alignLength(num2, length);
    for (int i = 0; i < length - 1; i++) {
        int bit1 = alignedNum1[i] - '0';
        int bit2 = alignedNum2[i] - '0';
        if (bit1 == 1 && bit2 == 1) {
            result += '1';
        } else {
            result += '0';
        }
    }
    return result;
}

// функция удаления ведущих нулей
string removeLeadingZeros(const string& num) {
    size_t pos = num.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return num.substr(pos);
}

// основная функция ускоренного сложения
string acceleratedAddition(const string& num1, const string& num2) {
    string a = removeLeadingZeros(num1);
    string b = removeLeadingZeros(num2);
    int step = 0;
    cout << "step " << step++ << ": a=" << a << " b=" << b << endl;
    while (b != "0") {
        string sum = calculateIntermediateSum(a, b);
        string carry = calculateCarry(a, b);
        a = removeLeadingZeros(sum);
        b = removeLeadingZeros(carry);
        cout << "step " << step++ << ": sum=" << sum << " carry=" << carry << endl;
        if (step > 100) break;
    }
    return a;
}

// функция проверки валионости двоичного числа
bool isValidBinary(const string& num) {
    if (num.empty()) return false;
    for (char c : num) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

int main() {
    string num1, num2;
    while (true) {
        cout << "enter first binary: ";
        cin >> num1;
        if (isValidBinary(num1)) break;
        cout << "use 0/1 only." << endl;
    }
    while (true) {
        cout << "enter second binary: ";
        cin >> num2;
        if (isValidBinary(num2)) break;
        cout << "use 0/1 only." << endl;
    }
    string result = acceleratedAddition(num1, num2);
    cout << "result: " << result << endl;

    return 0;
}