#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first; 
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> minHeap;
    for (int i = 0; i < n; ++i) {
        minHeap.push({matrix[i][0], {i, 0}});
    }
    for (int i = 0; i < k - 1; ++i) {
        pair<int, pair<int, int>> current = minHeap.top();
        minHeap.pop();

        int row = current.second.first;
        int col = current.second.second;
        if (col < n - 1) {
            minHeap.push({matrix[row][col + 1], {row, col + 1}});
        }
    }
    return minHeap.top().first;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout <<  kthSmallest(matrix, k) << endl;

    return 0;
}
