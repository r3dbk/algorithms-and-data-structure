#include <iostream>
#include <cmath>
using namespace std;

double findRoot(double a, double b, double delta) {
    double mid = (a + b) / 2;
    double fa = a - 2;
    double fm = mid - 2;
    if (fabs(fm) < delta || (b - a) < delta) {
        return mid;
    }
    if (fa * fm < 0) {
        return findRoot(a, mid, delta);
    } else {
        return findRoot(mid, b, delta);
    }
}

int main() {
    double a = 0, b = 3;
    double delta = 0.0001;

    double root = findRoot(a, b, delta);
    cout << "Корень уравнения: " << root;

    return 0;
}