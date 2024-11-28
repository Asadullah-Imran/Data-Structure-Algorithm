// Rakib is a cashier in the “Sundarban Courier Service”.When a slot comes to him with peoples stuffs and goods, people gather there excessively.In that time when someone ask Rakib about their stuffs,Rakib then faced many difficulties. Such finding their name in the list and delivery their products according to the products number level in the products list.

// So,Rakib wants to hire a programmer for write a code to sort his customers first letter of the name.So that he could find the person easily.Also sort the products number ascending to descending for delivering the products.

// You can use number of 2 Arrays or vectors. 
// You have to declare one in character and another in integer.
// You can help Rakib by only using “Selection Sort”.

// Input:
// First line, take a user input N.Thats denote the number of the customers.
// The second line contains N characters (Name1,Name2,Name3….NameN)
// Third line contains N integers of number level of the products(a1,a2,a3….aN)

// Output:
// ->After sorting the characters print it in ascending to descending order.
// ->After sorting the integers print it in ascending to descending order.

// Example:
// Inputs:
// 5
// e a c b d 
// 66 21 34 5 1 10

// Outputs:
// a b c d e 
// 1 5 10 21 34 66


#include <iostream>

// Function to perform selection sort on an array of integers
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the first element is the minimum
        int min = arr[i];
        int minIndex = i;

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];      // Update the minimum value
                minIndex = j;      // Update the index of the minimum value
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = min;
            arr[minIndex] = temp;
        }
    }
}

// Function to perform selection sort on an array of characters
void selectionSort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the first element is the minimum
        char min = arr[i];
        int minIndex = i;

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];      // Update the minimum value
                minIndex = j;      // Update the index of the minimum value
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            char temp = arr[i];
            arr[i] = min;
            arr[minIndex] = temp;
        }
    }
}

int main() {
    // Array of integers to be sorted
    int N = 5;
    int num[] = {21, 34, 5, 1, 10};

    // Array of characters to be sorted
    char ch[] = {'e', 'a', 'c', 'b', 'd'};

    // Print initial arrays
    std::cout << "Initial Integer Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Initial Character Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << ch[i] << " ";
    }
    std::cout << std::endl;

    // Sort both arrays
    selectionSort(num, N);
    selectionSort(ch, N);

    // Print sorted arrays
    std::cout << "Sorted Integer Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted Character Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << ch[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}