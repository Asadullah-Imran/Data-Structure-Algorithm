#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (k == 1)
        {
            cout << n << endl;
            continue;
        }

        vector<long long> v;
        long long p = 1;
        while (p <= n)
        {
            v.push_back(p);
            if (p > n / k)
                break;
            p *= k;
        }
        sort(v.begin(), v.end(), greater<long long>());
        long long count = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (n >= v[i])
            {
                count += n / v[i];
                n = n % v[i];
            }
        }
        cout << count << endl;
    }
    return 0;
}