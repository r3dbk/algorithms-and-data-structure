#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char firstUnique(const string& s) {
    unordered_map<char, pair<int, int>> m;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (m.find(c) == m.end()) {
            m[c] = {1, i};
        } else {
            m[c].first++;
        }
    }
    int minIndex = s.size();
    char result = '\0';
    for (const auto& p : m) {
        if (p.second.first == 1 && p.second.second < minIndex) {
            minIndex = p.second.second;
            result = p.first;
        }
    }
    return result;
}

int main() {
    string input;
    cout << "enter string: ";
    getline(cin, input);
    char res = firstUnique(input);
    if (res == '\0') {
        cout << "no unique" << endl;
    } else {
        cout << "first unique: " << res << endl;
    }

    return 0;
}
