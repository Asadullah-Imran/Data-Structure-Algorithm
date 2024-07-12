// Problem: Write a C program to implement the Selection Sort algorithm with the following additional requirements: 
// 1. The program should handle sorting based on user choice for either sorting only even or odd numbers within the array. 
// 2. The program should read an integer n from the user representing the number of elements in the array. 
// 3. The program should read n integers from the user and store them in an array. 
// 4. You should create a function named selectionSort() with the parameters int arr[], int n, char choice ('E' for sorting even numbers, 'O' for sorting odd numbers) which will sort only the selected type of numbers in ascending order, keeping the other numbers in their original positions.
//  5. The program should print the array after sorting the chosen type of numbers.
//  Constraints
//  • The number of elements, n, is between 1 and 1000.
//  • Each element in the array is an integer.
//  Example: 
// Input: 
// 5
//  64 25 12 22 11
//  E 
// Output: 
// 12 25 22 64 11
//  Input:
//  5 
// 64 25 12 22 11 
// O 
// Output: 64 11 12 22 25



#include <iostream>
void selectionSort2(int arr[], int n, char choice) {
    int reminder;

    if (choice == 'E' || choice == 'e') {
        reminder = 0;
    } else if (choice == 'O' || choice == 'o') {
        reminder = 1;
    } else {
        printf("Wrong choice input\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] % 2 == reminder) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] % 2 == reminder && arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap if a new minimum was found
            if (minIndex != i) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n, char choice){

    int reminder;

    if(choice=='E'||choice=='e'){
        reminder=0;
    }else if(choice=='O'||choice=='o'){
        reminder=1;
    }else{
        std::cout<<"Wrong choice input"<<std::endl;
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]%2==reminder){
        int min=arr[i];
        int minIndex=i;
            //  std::cout<<"target index ->"<<i<<std::endl;
            for(int j=i+1;j<n;j++){
                if(arr[j]%2==reminder && min>arr[j]){
                    min=arr[j];
                    minIndex=j;
                }
            }

            //now swap
            if(minIndex!=i){
            int temp= arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
            }
        }
        
    }
    
    
}



int main() {
    int n = 5;
    int arr[] = {64, 25, 12, 22, 11};
    char choice = 'O';
    char choice2 = 'E';

    std::cout << "Original array : ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Sort odd numbers
    selectionSort(arr, n, choice);
    std::cout << "Sorted array (odd): ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Reset the array
    int arr2[] = {0,28,9,11,64, 44,25, 12, 22, 11,2};
    n=11;
     std::cout << "Original array : ";
    for (int i = 0; i < n; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    // Sort even numbers
    selectionSort(arr2, n, choice2);
    std::cout << "Sorted array (even): ";
    for (int i = 0; i < n; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}