// You are given a sorted array of N distinct integers, and you are required to find the number of occurrences of a given integer K in this array using binary search. If the integer k is not present in the array, return 0.
// Example:
// Input:
//      int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6};
//       int n = sizeof(arr) / sizeof(arr[0]);
//       int k = 2;
// Output:
//      3
// Input:
//       int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6};
//       int n = sizeof(arr) / sizeof(arr[0]);
//       int k = 7;
// Output:
//      0

#include <iostream>

int findFrequency(int arr[],int n, int target, int firstOccurance){
    int low,high;
    int midIndex;
    low=firstOccurance;
    high= n-1;
    while(low<=high){
        midIndex=(low+high)/2;
        if(target==arr[midIndex] && arr[midIndex+1]!=target){
            return (midIndex-firstOccurance)+1;
        }else if(target>=arr[midIndex]){
            low=midIndex+1;
        }else if(target<arr[midIndex]){
            high=midIndex-1;
        }
    }
    return 1;
}


int findFirstOccurance(int arr[],int n,int target){
    int low =0;
    int high =n-1;
    int midIndex;
    while(low<=high){
        midIndex=(low+high)/2;
        if(target==arr[midIndex]  && arr[midIndex-1!=target]){
            return findFrequency(arr, n,  target,  midIndex);
        }
        else if(target>arr[midIndex]){
            low=midIndex+1;
        }else if(target<=arr[midIndex]){
            high=midIndex-1;
        }
    }
    return 0;
}

int main(){
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;
    int x=findFirstOccurance(arr,n,k);
    std::cout<< "The ocuurance of "<<k<<" is `"<< x<<"` times"<<std::endl;
}