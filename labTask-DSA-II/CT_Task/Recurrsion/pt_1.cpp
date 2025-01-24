// Write a recursive program to find the GCD of x and y where x, y are positive integers.
// (Hint: use Euclid's algorithm. Two ways to solve this.)

#include <iostream>
using namespace std;

// Recursive function to find GCD using Euclid's algorithm
int gcd_mod(int x, int y) {
    if (y == 0) {
        return x; // Base case: when the second number becomes 0
    }
    return gcd_mod(y, x % y); // Recursive step
}

int main() {
    int x, y;
    cout << "Enter two positive integers: ";
    cin >> x >> y;

    cout << "GCD of " << x << " and " << y << " is: " << gcd_mod(x, y) << endl;
    return 0;
}
