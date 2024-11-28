#include <iostream>

// arr [0,1,2,3,5,6,8,9]  => n=8

// if mid == mid index then search from right .... 
// if mid 

int binarySearch(int arr[], int n){
    int low, high,midIndex;
    low =0;
    high=n-1;

    if(arr[0]!=low){
        return low;
    }
    if(arr[n-1]==n-1){
        return n;
    }
    while(low<=high){
        midIndex=(low+high)/2;
        if(arr[midIndex]!= midIndex && arr[midIndex-1] == midIndex-1){
            return midIndex;
        }else if(arr[midIndex]!= midIndex){
            high=midIndex-1;
        }else if(arr[midIndex]== midIndex){
            low=midIndex+1;
        }
    }
    return -1;
}

int main(){

    int arr []={0,1,2,4,5,6,7};
    int size= sizeof(arr)/sizeof(arr)[0];
    
    // if(int x=binarySearch(arr,size)!=-1){
    //     std::cout<<"missing number "<<x<<std::endl;
    // }else{
    //     std::cout<<"There is no missing number"<<std::endl;
    // }

           std::cout<<"missing number "<<binarySearch(arr, size)<<std::endl;
}