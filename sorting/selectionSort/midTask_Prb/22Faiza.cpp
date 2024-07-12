// Problem
// Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that all the relative positions of the elements in the first array are the same as the elements in the second array A2[ ].
// See example for better understanding.
// Note: If elements are repeated in the second array, consider their first occurance only

// Sample input:
// N = 11 
// M = 4
// A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
// A2[] = {2, 1, 8, 3}
// Sample output :
// 2 2 1 1 8 8 3 5 6 7 9
// Array elements of A1[] are
// sorted according to A2[]. So 2 comes first
// then 1 comes, then comes 8, then finally 3
// comes, now we append remaining elements in
// sorted order.

// Your task is to complete the function sortA1ByA2() which takes the array A1[ ], array A2[ ] and their respective size N and M as input parameters and returns the sorted array A1[ ] such that the relative positions of the elements in A1[ ] are same as the elements in A2[ ]. For the elements not present in A2[ ] but in A1[ ], it appends them at the last in increasing order. 


#include <iostream>

// void sortA1ByA2(int a1[],int a2[],n,m){
//     //selection sort
//     for(int i=0;i<n-1;i++){
//         int min=a1[i];
//         int minIndex=a1[i];

//         //here we need to do some operation 
//         for(int j=i+1;j<n;j++){
//             if(min>a1[j]){
//                 min=a1[j];
//                 minIndex=j;
//             }
//         }


//         //swap the value
//         if(minIndex!=i){
//             int temp= arr[i];
//             arr[i]=min;
//             arr[minIndex]=temp;
//         }
//     }
// }

void selectionSort2(int A1[], int N, int A2[], int M) {
    // Traverse through all elements of A2
    for (int i = 0; i < M; ++i) {
        // Place all occurrences of A2[i] in the correct order in A1
        for (int j = 0; j < N; ++j) {
            if (A1[j] == A2[i]) {
                // Swap to move A2[i] to the correct position
                int temp = A1[i];
                A1[i] = A1[j];
                A1[j] = temp;
                i++;
            }
        }
        i--; // Adjust i because of the extra increment in the inner loop
    }

    // Selection sort for remaining elements not in A2
    // for (int i = M; i < N-1; i++) {
    //     int minIndex = i;
    //     for (int j = i+1; j < N; j++) {
    //         if (A1[j] < A1[minIndex]) {
    //             minIndex = j;
    //         }
    //     }
    //     // Swap the found minimum element with the first element
    //     int temp = A1[minIndex];
    //     A1[minIndex] = A1[i];
    //     A1[i] = temp;
    // }
}
// Function to perform selection sort
void selectionSort(int A1[], int N, int A2[], int M) {
    // Traverse through all elements of A2
    for (int i = 0; i < M; ++i) {
        // Find the position of the element A2[i] in A1
        int pos = -1;
        for (int j = 0; j < N; ++j) {
            if (A1[j] == A2[i]) {
                pos = j;
                break;
            }
        }

        // If A2[i] is found in A1, swap A1[i] and A1[pos]
        if (pos != -1 && pos != i) {
            // Swap elements in A1 to maintain order of A2
            int temp = A1[i];
            A1[i] = A1[pos];
            A1[pos] = temp;
        }
    }
}

int main(){
    int N = 11 ;
    int  M = 4;
    int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    std::cout << "Initial Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << A1[i] << " ";
    }
    std::cout << std::endl;    
    selectionSort(A1,N,A2,M);
    std::cout << "Sorted Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << A1[i] << " ";
    }
    std::cout << std::endl;  

}