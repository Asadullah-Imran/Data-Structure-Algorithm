#include <iostream>

bool isABazokaAndMocha(int arr[], int n) {
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
        //Array has breakpoints one time.
        return arr[n-1]<=arr[0];
    }
    //array has many breakpoints
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
        if (isABazokaAndMocha(arr,n)) {
            std::cout <<"Yes"<<std::endl;
        } else {
            std::cout << "No"<<std::endl;
        }
    }
   
}
