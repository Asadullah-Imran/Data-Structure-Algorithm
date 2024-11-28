// You are given an integer N. Your task is to print numbers from 1 to N first, 
// then N to 1(in reverse order) using recursion.

#include <iostream>
using namespace std;

void nto1 (int n){
    if(n<1){return;}
    cout<<n;
    nto1(n-1);
}

void _1ton (int n){
    if(n<1){return;}
    _1ton(n-1);
    cout<<n;
}

int main(){
    int n;
    cin>>n;
   // nto1(n);
    _1ton(n);
}