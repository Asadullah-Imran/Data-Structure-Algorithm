#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        int max1 = 0;
        int max2 = 0;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n; i += 2)
        {
            max1 = max(max1, arr[i]);
            count1++;
        }
        for (int i = 1; i < n; i += 2)
        {
            max2 = max(max2, arr[i]);
            count2++;
        }
        int score1 = max1 + count1;
        int score2 = max2 + count2;
        cout << max(score1, score2) << endl;
    }

    return 0;
}