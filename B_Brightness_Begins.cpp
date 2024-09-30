#include <iostream>
#include <cmath>
using namespace std;

long long calculateMinimumN(long long k)
{
    long long n = k + static_cast<long long>(sqrt(k));
    long long sqrt_n;
    while (true)
    {
        sqrt_n = static_cast<long long>(sqrt(n));
        if (n - sqrt_n == k)
        {
            return n;
        }
        n++;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long k;
        cin >> k;

        cout << calculateMinimumN(k) << endl;
    }

    return 0;
}
