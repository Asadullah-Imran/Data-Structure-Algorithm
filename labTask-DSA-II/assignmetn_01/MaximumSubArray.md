# Maximum Subarray Explanation

This C++ program finds the maximum sum of a contiguous subarray within a given array using the Divide and Conquer approach. Here's a detailed explanation of the code:

## Structure Definition
```cpp
struct Subarray {
    int low;
    int high;
    int sum;
};
```
The `Subarray` structure holds the starting index (`low`), ending index (`high`), and the sum (`sum`) of the subarray.

## Finding Maximum Crossing Subarray
```cpp
Subarray findMaximumCrossingSubArray(const int A[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;

    for (int i = mid; i >= low; --i) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = mid + 1;

    for (int j = mid + 1; j <= high; ++j) {
        sum += A[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }

    return {maxLeft, maxRight, leftSum + rightSum};
}
```
This function finds the maximum subarray that crosses the midpoint of the array. It calculates the maximum sum of the left and right parts separately and then combines them.

## Finding Maximum Subarray
```cpp
Subarray findMaximumSubArray(const int A[], int low, int high) {
    if (low == high) {
        return {low, high, A[low]};
    } else {
        int mid = (low + high) / 2;
        Subarray leftSubarray = findMaximumSubArray(A, low, mid);
        Subarray rightSubarray = findMaximumSubArray(A, mid + 1, high);
        Subarray crossSubarray = findMaximumCrossingSubArray(A, low, mid, high);

        if (leftSubarray.sum >= rightSubarray.sum && leftSubarray.sum >= crossSubarray.sum) {
            return leftSubarray;
        } else if (rightSubarray.sum >= leftSubarray.sum && rightSubarray.sum >= crossSubarray.sum) {
            return rightSubarray;
        } else {
            return crossSubarray;
        }
    }
}
```
This recursive function divides the array into two halves and finds the maximum subarray in the left half, right half, and the crossing subarray. It then returns the subarray with the maximum sum.

## Main Function
```cpp
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    Subarray result = findMaximumSubArray(A, 0, n - 1);
    cout << "Maximum Sum: " << result.sum << "\n";
    return 0;
}
```
The `main` function reads the number of elements and the elements of the array from the user, calls the `findMaximumSubArray` function, and prints the maximum sum of the subarray.

This implementation efficiently finds the maximum subarray sum with a time complexity of O(n log n).