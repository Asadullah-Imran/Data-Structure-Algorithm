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
            std::cout <<"Yes"<<std::endl;
        } else {
            std::cout << "No"<<std::endl;
        }
    }
   
}
