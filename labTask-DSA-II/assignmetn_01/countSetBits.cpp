#include <iostream>
using namespace std;

int countSetBits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 2) + countSetBits(n / 2);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Set-bits of the number: " << countSetBits(n) << endl;
    return 0;
}