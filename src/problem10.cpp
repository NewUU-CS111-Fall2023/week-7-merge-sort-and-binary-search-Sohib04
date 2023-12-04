#include <iostream>
#include <vector>
#include <algorithm>

int kthFactor(int n, int k) {
    std::vector<int> factors;
    
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }

    if (k > factors.size()) {
        return -1;
    } else {
        return factors[k - 1];
    }
}

int main() {
    int n, k;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;
    std::cout << "Enter k: ";
    std::cin >> k;

    int result = kthFactor(n, k);

    if (result == -1) {
        std::cout << "n has less than k factors." << std::endl;
    } else {
        std::cout << "The " << k << "th factor of " << n << " is: " << result << std::endl;
    }

    return 0;
}
