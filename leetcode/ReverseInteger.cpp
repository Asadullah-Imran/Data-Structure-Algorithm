#include <iostream>
#include <climits>

int reverse(int x) {
    int reverse=0;
    while(x!=0){
            int lastDigit = x%10;
        if(reverse> INT_MAX /10 || reverse==INT_MAX && lastDigit>7){return 0;}
        if(reverse< INT_MIN /10 || reverse==INT_MIN && lastDigit<-8){return 0;}
            x=x/10;
            reverse = reverse*10+lastDigit;
    }
    return reverse;
}

int main() {
    // int x = 123;
    // std::cout << reverse(x) << std::endl; // Expected output: 321

    // int x1 = -123;
    // std::cout << reverse(x1) << std::endl; // Expected output: -321

    // int x2 = 120;
    // std::cout << reverse(x2) << std::endl; // Expected output: 21

    // int x3 = 0;
    // std::cout << reverse(x3) << std::endl; // Expected output: 0

    // int x4 = 1534236469;
    // std::cout << reverse(x4) << std::endl; // Expected output: 0

    int x5 = -2147483648;
    std::cout << reverse(x5) << std::endl; // Expected output: 0

    return 0;
}