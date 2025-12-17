#include <iostream>
#include <vector>
using namespace std;

int countPaths(int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int j = 1; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < n; i++) dp[i][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][n - 1];
}

int main() {
    int n;
    cout << "enter grid size n: ";
    cin >> n;
    int result = countPaths(n);
    cout << "number of paths: " << result << endl;
    return 0;
}
