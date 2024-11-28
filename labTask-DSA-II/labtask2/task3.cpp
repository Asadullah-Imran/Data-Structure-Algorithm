// Task 3: Thor's Hammer Energy Amplification

// Thor is preparing for his next battle against cosmic threats. His hammer, Mjölnir, can amplify its energy output by harnessing the power of magical elements. These elements are represented as an array of integers, and the energy amplification is the product of all the element values.
// Unfortunately, Thor's calculations were disrupted by Loki's tricks, and he now needs your help to create a recursive program that computes the total energy amplification from an array of magical elements.
// Your task is to write a recursive function to find the product of all elements in the array.


#include <iostream>
#include <vector>

using namespace std;

int toMul(vector <int> v,int n){
    if(n==0){
        return 1;
    }


    return v[n-1]*toMul(v,n-1) ;
}

int main (){
    int n;
    cin >> n;
    vector <int> v1;
    for(int i =0; i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    } 
      int result = toMul(v1, n);
      cout <<result;
}