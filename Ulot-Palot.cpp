#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int res;
        bool result = false;
        int x = -1;
        int y = -1;

        for (int i = l; i <= r; i++)
        {
            if (result)
            {
                break;
            }
            for (int j = i + 1; j <= r; j++)
            {
                res = lcm(i, j);
                // cout << "result of lcm(" << i << ", " << j << ") = " << res << endl;
                if (res <= r)
                {
                    x = i;
                    y = j;
                    result = true;
                    break;
                }
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
