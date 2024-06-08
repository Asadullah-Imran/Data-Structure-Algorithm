//Find the last Occurrence og a number in a sorted array

// arr[1,2,2,2,3,5,6,8] =>n=8
// if key < arr[mid]  high => mid-1;
// if key > arr[mid]  low => mid+1;

//if key == arr[mid]   --> then we again check key==arr[mid+1];


#include <iostream>


int binarySearch(int arr[], int n, int key){
    int low, high,midIndex;
    low =0;
    high=n-1;
    while(low<=high){
        midIndex=(low+high)/2;
        if(key==arr[midIndex] && key!= arr[midIndex] ){
            return midIndex;
        }else if (key>arr[midIndex]){
            low=midIndex+1;
        }else if(key<arr[midIndex]){
            high=midIndex-1;
        }
    }
    return -1;
}


int main(){

    int arr[8]={1,2,2,2,3,5,6,8};
    int size= sizeof(arr)/sizeof(arr)[0];
    // std::cout<<"Type a number to search: ";
    int searchNum=2;
    // std::cin>>searchNum;
    if(int x=binarySearch(arr,size,searchNum)!=-1){
        std::cout<<"last Occarence index is "<<x<<std::endl;
    }else{
        std::cout<<"not Matched"<<std::endl;
    }
}
