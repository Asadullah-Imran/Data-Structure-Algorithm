#include <iostream>


int binarySearch(int arr[], int n, int key){
    int low, high,midIndex;
    low =0;
    high=n-1;
    while(low<=high){
        midIndex=(low+high)/2;
        if(key==arr[midIndex]){
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

    int arr[10]={1,4,7,9,12,23,34,45,56,67};
    int size= sizeof(arr)/sizeof(arr)[0];
    std::cout<<"Type a number to search: ";
    int searchNum;
    std::cin>>searchNum;
    if(binarySearch(arr,size,searchNum)!=-1){
        std::cout<<"Matched"<<std::endl;
    }else{
        std::cout<<"not Matched"<<std::endl;
    }
}