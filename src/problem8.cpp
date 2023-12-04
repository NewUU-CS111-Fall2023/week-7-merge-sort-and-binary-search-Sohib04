#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int missing = nums.size(); 

    for (int i = 0; i < nums.size(); ++i) {
        missing ^= i ^ nums[i];
    }

    return missing;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> nums;
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n-1; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    int missing = missingNumber(nums);

    std::cout << "The missing number is: " << missing << std::endl;

    return 0;
}

