#include <iostream>

bool isIncreasing(int arr[], int n, int &index) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            index = i;
            return false;
        }
    }
    return true;
}

bool isDecreasing(int arr[], int n, int &index) {
    for (int i = index; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            index = i;
            return false;
        }
    }
    return true;
}

void splitAndConcat(int arr[], int n, int prevIndex, int index) {
    int size1 = prevIndex + 1; // Include the element at prevIndex
    int size2 = index - prevIndex;

    int temp[size1];
    for (int i = 0; i < size1; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - size1; i++) {
        arr[i] = arr[i + size1];
    }

    for (int i = 0; i < size1; i++) {
        arr[n - size1 + i] = temp[i];
    }

    std::cout << "Array after first split and concat: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // int temp2[size2];
    // for (int i = 0; i < size2; i++) {
    //     temp2[i] = arr[i];
    // }

    // for (int i = 0; i < n - size2; i++) {
    //     arr[i] = arr[i + size2];
    // }

    // for (int i = 0; i < size2; i++) {
    //     arr[n - size2 + i] = temp2[i];
    // }
}

bool isBazokaAndMocha(int arr[], int n) {
    int index = 0;
    int prevIndex;
    if (isIncreasing(arr, n, index)) {
        // It is a fully increasing array
        std::cout << "Already increasing array" << std::endl;
        return true;
    } else {
        // It is not a fully increasing array
        // At `index` it starts decreasing
        std::cout << "Decreasing array starts at index " << index << std::endl;
        prevIndex = index;
        // Now check how much portion is decreasing
        if (isDecreasing(arr, n, index)) {
            // All are decreasing
            std::cout << "All elements are decreasing" << std::endl;
        } else {
            std::cout << "Decreasing array ends at index " << index << std::endl;
            // Now split and concat
            splitAndConcat(arr, n, prevIndex, index);
            std::cout << "Split and concat completed" << std::endl;
            for (int i = 0; i < n; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            if (isIncreasing(arr, n, index)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    if (isBazokaAndMocha(arr, n)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
