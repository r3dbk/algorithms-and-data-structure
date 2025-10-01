#include <iostream>
#include <vector>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> counts(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[i]) {
                counts[i]++;
            }
        }
    }
    return counts;
}

int main() {
    vector<int> nums;
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "error: array size must be a positive number!" << endl;
        return 1;
    }
    cout << "enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "element " << (i + 1) << ": ";
        cin >> num;
        nums.push_back(num);
    }
    vector<int> result = countSmaller(nums);
    cout << "\nresult: [";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}