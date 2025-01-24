#include <iostream>
#include <climits>
using namespace std;

struct Subarray {
    int low;
    int high;
    int sum;
};

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