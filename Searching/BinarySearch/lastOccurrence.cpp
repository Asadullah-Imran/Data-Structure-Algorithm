//Find the last Occurrence og a number in a sorted array

// arr[1,2,2,2,3,5,6,8] =>n=8
// if key < arr[mid]  high => mid-1;
// if key > arr[mid]  low => mid+1;

//if key == arr[mid]   --> then we again check key==arr[mid+1];


#include <iostream>
//int arr[]={1,2,2,2,3,3,5,6,8};
int findFirstOccurrence(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if ((arr[mid] == key) && (arr[mid-1] != key)) {  // mid value != next value means last occurrence... 
            return mid;
        }
        else if (key > arr[mid]) {
            low = mid + 1;
        }
        else if (key <= arr[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}
int findLastOccurrence(int arr[], int n, int key){
    int low, high,midIndex;
    low =0;
    high=n-1;
    while(low<=high){
        midIndex=(low+high)/2;
        if(arr[midIndex]==key&& arr[midIndex+1]!=key ){
            return midIndex;
        }else if (key>=arr[midIndex]){
            low=midIndex+1;
        }else if(key<arr[midIndex]){
            high=midIndex-1;
        }
    }
    return -1;
}


int main(){

    int arr[]={1,2,2,2,3,3,3,3,3,3,5,6,8};
    int size= sizeof(arr)/sizeof(arr[0]);
    // std::cout<<"Type a number to search: ";
    int searchNum;
    std::cin>>searchNum;

    int fO,lO;

    fO=findFirstOccurrence(arr,size,searchNum);
    lO=findLastOccurrence(arr,size,searchNum);

    int count= (lO-fO)+1;

    // int x=binarySearch(arr,size,searchNum);
    // if(x!=-1){
    //     std::cout<<"last Occarence index is "<<x<<std::endl;
    // }else{
    //     std::cout<<"not Matched"<<std::endl;
    // }
        std::cout<<"Count "<<count<<std::endl;
}


/* Find the last occurrence of a number in a sorted array...*/

// Given sorted array that means we need to go for binary search....





