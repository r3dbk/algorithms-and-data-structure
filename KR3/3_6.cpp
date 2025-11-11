#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        cout << "error: division by zero" << endl;
        return 1;
    }
    int left = 0;
    int right = a;
    int p = 0;
    // метод
    while (left <= right) {
        int mid = (left + right) / 2;

        if (b * mid <= a) {
            p = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int q = a - b * p;
    cout << "quotient: " << p << endl;
    cout << "remainder: " << q << endl;

    return 0;
}