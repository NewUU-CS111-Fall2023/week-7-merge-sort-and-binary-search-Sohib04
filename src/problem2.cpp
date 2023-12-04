#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }

    long long initialBeautifulness = 0;
    for (int i = 0; i < n; ++i) {
        initialBeautifulness += abs(permutation[i] - (i + 1));
    }

    long long maxBeautifulness = initialBeautifulness;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long swappedBeautifulness = initialBeautifulness - abs(permutation[i] - (i + 1)) - abs(permutation[j] - (j + 1));
            swappedBeautifulness += abs(permutation[i] - (j + 1)) + abs(permutation[j] - (i + 1));
            maxBeautifulness = max(maxBeautifulness, swappedBeautifulness);
        }
    }

    cout << maxBeautifulness << endl;

    return 0;
}
