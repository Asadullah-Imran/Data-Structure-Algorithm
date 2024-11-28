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

// Function to sort array a1 according to the order defined by array a2
void sortA1ByA2(int a1[], int a2[], int n, int m) {
    int index = 0; // Index to keep track of the position in a1

    // Loop through each element in a2
    for (int i = 0; i < m; i++) {
        // Loop through the remaining elements in a1
        for (int j = index; j < n; j++) {
            // If the current element in a1 matches the current element in a2
            if (a1[j] == a2[i]) {
                // Swap the matching element with the element at the current index
                int temp = a1[index];
                a1[index] = a1[j];
                a1[j] = temp;
                index++; // Move the index forward
            }
        }
    }

    // Perform selection sort on the remaining elements in a1
    for (int i = index; i < n - 1; i++) {
        int min = a1[i];
        int minIndex = i;
        
        // Find the minimum element in the remaining unsorted portion of the array
        for (int j = i + 1; j < n; j++) {
            if (min > a1[j]) {
                min = a1[j]; // Update the minimum value
                minIndex = j; // Update the index of the minimum value
            }
        }

        // Swap the found minimum element with the current element
        if (minIndex != i) {
            int temp = a1[i];
            a1[i] = min;
            a1[minIndex] = temp;
        }
    }
}

int main() {
    

    // Define the arrays
    int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    
    // Define the size of the arrays
    int N = sizeof(A1)/sizeof(A1[0]);
    int M = sizeof(A2)/sizeof(A2[0]);
    // Print the initial array
    std::cout << "Initial Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << A1[i] << " ";
    }
    std::cout << std::endl;

    // Sort array A1 according to the order defined by array A2
    sortA1ByA2(A1, A2, N, M);

    // Print the sorted array
    std::cout << "Sorted Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << A1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
