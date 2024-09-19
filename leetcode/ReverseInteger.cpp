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

    int x5;
    std::cin>>x5;
    std::cout << reverse(x5) << std::endl; // Expected output: 0

    return 0;
}