#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input); // чтение всей строки с пробелами
    vector<string> words; // вектор для хрпнения слов
    stringstream ss(input); // используем stringstream для разбиения на слова
    string word;
    // разбиваем на слова и сохраняем в вектор
    while (ss >> word) {
        words.push_back(word);
    }
    // выводим в обратном порядке
    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) cout << " ";
    }
    return 0;
}
