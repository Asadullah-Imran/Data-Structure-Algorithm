// Provide a program that sorts an array of integers using the insertion sort algorithm and then calculates and prints the mean and median of the sorted array. Remember that arrays in C are passed by reference. The formula for the mean is (ElementsN). 
// The formulae for median are:
// Odd: (N+12)th Term 
// Even:(N2+N+122)th Term
// Sample input: 12, 13, 13, 22, 24, 10,  13, 15, 15, 16, 16, 18, 25, 23, 24
// Sample output:
// Sorted Array: 10 12 13 13 13 15 15 16 16 18 22 23 24 24 25
// Mean: 17.27
// Median: 16.00 


#include <iostream>


void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        
        int j=i-1;
        while(j>-1 && key<arr[j]){
            // right shift element
            arr[j+1]=arr[j];
            j--;
        }
        // now we set the key in right position
        arr[j+1]=key;
    }
}

double mean(int arr[],int n){
    double sum=0;
    for (int i = 0; i < n; i++) {
        sum+=arr[i];
    }
    return sum/n;
}
double median(int arr[],int n){
    int i;
   if(n%2==0){ //even item
    i=(n/2);
    i--;
    std::cout<<"i is "<<i<<std::endl;
    return (arr[i]+arr[i+1])/2.0;
   }else{ // odd number
    i=(n+1)/2;
    i--;
    return arr[i];
   }

    
}

int main(){

    int arr[]={12, 13, 13, 22, 24, 10,  13, 15, 15, 16, 16, 18, 25, 23, 24};
    int n= sizeof(arr)/sizeof(arr[0]);
    std::cout << "Initial Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; //for line break
    insertionSort(arr,n);
    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;//for line break
    std::cout<<"Mean: "<<mean(arr,n)<<std::endl;
    std::cout<<"Median: "<<median(arr,n)<<std::endl;

}
