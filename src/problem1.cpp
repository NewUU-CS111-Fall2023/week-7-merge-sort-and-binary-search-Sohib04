/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <algorithm>

int sumOfRemainingNumbers(std::vector<int>& arr) {
    int sum = 0;
    int n = arr.size();

    for (int i = 0; i < n - 2; ++i) {
        int len = n - i;
        if (len % 2 == 0 || len <= 2) {
            break;
        }

        std::vector<int> medians;
        for (int j = i; j < n; ++j) {
            if (j - i + 1 > 2 && (j - i + 1) % 2 != 0) {
                std::vector<int> subarray(arr.begin() + i, arr.begin() + j + 1);
                std::sort(subarray.begin(), subarray.end());
                medians.push_back(subarray[(j - i) / 2]);
            }
        }

        std::sort(medians.begin(), medians.end());
        int minMedian = medians.front();

        auto it = std::find(arr.begin() + i, arr.end(), minMedian);
        if (it != arr.end()) {
            arr.erase(it);
            n--;
        }
    }

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int T;
    std::cout << "Enter the number of test cases (T): ";
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        std::cout << "Enter the size of the array for test case " << t + 1 << ": ";
        std::cin >> N;

        std::vector<int> arr(N);
        std::cout << "Enter the elements of the array: ";
        for (int i = 0; i < N; ++i) {
            std::cin >> arr[i];
        }

        int result = sumOfRemainingNumbers(arr);
        std::cout << "Sum of remaining numbers after operations for test case " << t + 1 << ": " << result << std::endl;
    }

    return 0;
}


