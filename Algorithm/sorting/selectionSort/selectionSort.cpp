#include <iostream>


void selectionSort(int arr[], int n){
    for(int i= 0;i<n-1;i++){
        int min = arr[i];
        int minIndex= i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j]; 
                minIndex=j;
            }
        }
        //now we can swap min
        if(minIndex!=i){
        int temp=arr[i];
        arr[i]=min;
        arr[minIndex]=temp;
        }
    }
}


int main(){

// suppose the array is 
int arr[]={5,9,2,7,1,5,6,2,3,4,1};
int arrLength= sizeof(arr)/sizeof(arr[0]); //this is how you can find the size fo an array
// std::cout<<"array size is "<<arrLength<<std::endl;

//now we are gonna sort the array 
selectionSort(arr,arrLength);

for (int i=0; i < arrLength;i++){
    std::cout<< arr[i]<< ", "; 
}

    std::cout<< std::endl; 
}
