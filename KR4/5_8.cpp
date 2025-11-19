#include <iostream>
using namespace std;

int F(int n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return F(n / 2);
    } else {
        return F(n / 2) + F(n / 2 + 1);
    }
}

int main() {
    int n;
    cin >> n;
    cout << F(n);
    
    return 0;
}