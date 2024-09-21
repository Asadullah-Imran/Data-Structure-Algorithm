#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t-->0) {
        int n, k;
        cin >> n >> k;
        int s = max(1, n - k + 1);
        int nLeaves = (n * (n + 1)) / 2 - ((s - 1) * s) / 2;
        if (nLeaves % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}