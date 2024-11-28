#include <iostream>

int ceilValue(int a, int b){
    return (a+b-1)/b;
}

void insertionSort(int arr[], int n){
    int key,j;
    for(int i=0;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&& arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int medianOfAnArray(int arr[],int n){
    insertionSort(arr,n);
    int result=ceilValue(n,2);

    return result=arr[result-1];
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

//  for(int i=0;i<n;i++){
//         std::cout<<arr[i]<<" ";
//     }
//     std::cout<<std::endl<<5/2<<" ";
    int result=medianOfAnArray(arr,n);
    std::cout<<result;
}