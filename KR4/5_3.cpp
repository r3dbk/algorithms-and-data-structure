#include <iostream>
#include <string>
#include <vector>
using namespace std;

// создаем префикс -функцию для шаблона
vector<int> buildPrefix(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m, 0);
    int k = 0;

    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pi[i] = k;
    }
    return pi;
}

// поиск всех вхождений шаблона в текст
vector<int> findPattern(const string& text, const string& pattern) {
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return positions;

    vector<int> pi = buildPrefix(pattern);
    int q = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            positions.push_back(i - m + 1);
            q = pi[q - 1];
        }
    }

    return positions;
}

int main() {
    string text, pattern;

    cin >> text >> pattern;

    vector<int> result = findPattern(text, pattern);

    cout << "Position: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }

    return 0;
}