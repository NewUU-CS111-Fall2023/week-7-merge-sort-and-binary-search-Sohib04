#include <iostream>

double recursivePow(double x, int n) {
    if (n == 0) {
        return 1.0;
    } else if (n > 0) {
        double half = recursivePow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    } else {
        return 1.0 / recursivePow(x, -n);
    }
}

int main() {
    double x = 2.0;
    int n = 5;

    double result = recursivePow(x, n);

    std::cout << x << " raised to the power " << n << " is: " << result << std::endl;

    return 0;
}
