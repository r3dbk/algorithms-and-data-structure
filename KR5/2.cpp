#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void countChars(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    cout << "Character frequency:\n";
    for (const auto& pair : freq) {
        cout << "'" << pair.first << "' : " << pair.second << endl;
    }
}

int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    countChars(input);

    return 0;
}
