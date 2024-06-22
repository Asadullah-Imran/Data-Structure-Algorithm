#include <iostream>


int binarySearch(int arr[], int size, int searchNum){
    int low,high,midIndex;
    low=0;
    high=size-1;

    while(low<=high){
        //first task is to find mid Index
        midIndex=(low+high)/2;
        if(searchNum==arr[midIndex]){
            return midIndex;
        }else if(searchNum>arr[midIndex]){
            low=midIndex+1;
        }else if(searchNum<arr[midIndex]){
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