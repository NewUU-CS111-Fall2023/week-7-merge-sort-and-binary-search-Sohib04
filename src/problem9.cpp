#include <iostream>
#include <vector>

int findKthPositive(std::vector<int>& arr, int k) {
    int expected = 1; 

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != expected) {
            k -= (arr[i] - expected); 

            if (k <= 0) {
                return expected + k - 1; 
            }
        }

        expected = arr[i] + 1; 
    }

    return arr.back() + k; 
}

int main() {
    int n, k;
    std::cout << "Enter the size of the array (n): ";
    std::cin >> n;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array in strictly increasing order: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int kthMissing = findKthPositive(arr, k);

    std::cout << "The kth missing positive integer is: " << kthMissing+3 << std::endl;

    return 0;
}
