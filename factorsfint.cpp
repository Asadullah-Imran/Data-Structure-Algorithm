#include <iostream>
#include <cmath> 
using namespace std;

int countFactors(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                count += 1;
            }
            else
            {
                count += 2;
            }
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int count = 0;
        int i = 1;

        while (n != count)
        {
            int factors = countFactors(i);

            if (factors % 2 == 0)
            {
                count++;
            }
            i++;
        }
        cout << i - 1 << endl;
    }
}
