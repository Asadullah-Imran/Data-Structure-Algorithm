#include <iostream>

// bool isIncreasing(int arr[], int n, int &index) {
//     for (int i = 0; i < n - 1; i++) {
//         if (arr[i] > arr[i + 1]) {
//             index = i;
//             return false;
//         }
//     }
//     return true;
// }

bool isIncreasing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
bool isOk(int arr[], int n) {
int breakpoint=0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
           breakpoint++;
        }
    }
     if (breakpoint == 0) {
        // Array is already sorted
        return true;
    }
    if(breakpoint==1){
        return arr[n-1]<=arr[0];
    }
    return false;
    
}
// void decreasingAndConcat(int arr[],int n,int decreasingIndex){
//     int decSize=decreasingIndex+1;
//     int decArr[decSize];
//     //just load the shifting part
//     for(int i=0; i<decSize;i++){
//         decArr[i]=arr[i];
//     }
//     for(int i=0;i<n;i++){
//         if(i<n-decSize){
//             arr[i]=arr[i+decSize];
//         } else{
//             arr[i]=decArr[i-(n-decSize)];
//         }
//     }
// }

// bool isBazokaAndMocha(int arr[],int n){
// int decreasingIndex=-1;
// if(isIncreasing(arr,n,decreasingIndex)){
//     return true;
// }else{
//     //std::cout<<"Decreasign index is "<<decreasingIndex<<std::endl;

//     //Now i want to split the part start to decreasing index and concat to its end

//     decreasingAndConcat(arr,n,decreasingIndex);
//     // for(int i=0; i<n;i++){
//     //     std::cout<<arr[i]<< " ";
//     // }
//     if(isIncreasing(arr,n,decreasingIndex)){
//         return true;
//     }else{
//         return false;
//     }

// }
//     return false;

// }



int main() {
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        if (isIncreasing(arr,n)||isOk(arr,n)) {
            std::cout <<"Yes";
        } else {
            std::cout << "No";
        }
    }
   
}
