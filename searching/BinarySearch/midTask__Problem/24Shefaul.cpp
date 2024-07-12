// Imagine a sorted array at ascending that got rotated once or multiple times. Now write a program that returns the amount of time the array got rotated. Solve this at O(logN) time. Note:Here's the rotation in clockwise order.
// Example: 
// Input: [4,5,6,7,1,2,3]
// Output: 4
// Input: [5,6,7,1,2,3,4]
// Output: 3


#include <iostream>


int binarySearch(int arr[],int n){
    int low,high,midIndex;
    low=0,high=n-1;
    if(arr[low]<=arr[high]){
        return 0;
    }
    while(low<=high){
        midIndex=(low+high)/2;

        int next= (midIndex+1)%n;
        int prev= (midIndex-1+n)%n;

        if(arr[midIndex]<arr[prev] && arr[midIndex]<arr[next]){
            //got the buster
            return n-midIndex;
        }else if(arr[midIndex]>=arr[high]){
            low=midIndex+1;
        }else if(arr[midIndex]<arr[high]){
            high=midIndex-1;
        }
    }
    return 0;
}


int main(){
    // int nums[] = {1,2,3,4,5,6,7}; //0
    int nums[] = {7,1,2,3,4,5,6}; //6
    // int nums[] = {2,3,4,5,6,7,1}; //1
    // int nums[] = {4,5,6,7,1,2,3};
    // int nums[] = {4,5,6,7,1,2,3};
    // int nums[] = {4,5,6,7,1,2,3};
    int n = sizeof(nums) / sizeof(nums[0]);

    std::cout<<"How many rotation: "<<binarySearch(nums, n)<<std::endl;

}