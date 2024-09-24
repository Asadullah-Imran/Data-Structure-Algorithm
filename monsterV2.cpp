#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            arr.push_back(make_pair(abs(a - k), i + 1));
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            cout << arr[i].second << " ";
        }
        cout << endl; // Add a newline after each test case
    }
    return 0;
}