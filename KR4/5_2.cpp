#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input); // чтение всей строки с пробелами
    stringstream ss(input);
    string current_word;
    string longest_word;
    int max_length = 0;
    while (ss >> current_word) {
        // сравниваем длину текущего слова с максимальной
        if (current_word.length() > max_length) {
            max_length = current_word.length();
            longest_word = current_word; // сохраняем 1е самое длинное слово
        }
    }
    cout << longest_word;
    return 0;
}