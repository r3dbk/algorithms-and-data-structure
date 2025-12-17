#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int capac(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "enter number of items: ";
    cin >> n;
    cout << "enter capacity: ";
    cin >> W;
    vector<int> weights(n), values(n);
    cout << "enter " << n << " weights: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
    cout << "enter " << n << " values: ";
    for (int i = 0; i < n; i++) cin >> values[i];
    int result = capac(W, weights, values);
    cout << "maximum value: " << result << endl;

    return 0;
}
