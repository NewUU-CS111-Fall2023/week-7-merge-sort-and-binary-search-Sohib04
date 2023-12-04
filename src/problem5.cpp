#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    
    for (int num : nums) {
        freqMap[num]++;
    }

    auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

    for (auto& entry : freqMap) {
        minHeap.push({entry.first, entry.second});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }

    return result;
}

int main() {
    int size, k;
    cin >> size;

    vector<int> nums(size);
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    cin >> k;

    vector<int> result = topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
