#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < M; ++i) {
            cin >> B[i];
        }

        int i = 0, j = 0;
        vector<int> mergedArray;
        while (i < N && j < M) {
            if (A[i] >= B[j]) {
                mergedArray.push_back(A[i]);
                i++;
            } else {
                mergedArray.push_back(B[j]);
                j++;
            }
        }
        while (i < N) {
            mergedArray.push_back(A[i]);
            i++;
        }
        while (j < M) {
            mergedArray.push_back(B[j]);
            j++;
        }
        for (int k = 0; k < mergedArray.size(); ++k) {
            cout << mergedArray[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
