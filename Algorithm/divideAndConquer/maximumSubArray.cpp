#include <iostream>
#include <climits>
using namespace std;

// Function to find the maximum crossing sum
int findMaxCrossingSum(int arr[], int left, int mid, int right) {
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }
    
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    
    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using Divide and Conquer
int maxSubArraySum(int arr[], int left, int right) {
    if (left == right) // Base case: only one element
        return arr[left];
    
    int mid = (left + right) / 2;
    
    int maxLeftSum = maxSubArraySum(arr, left, mid);
    int maxRightSum = maxSubArraySum(arr, mid + 1, right);
    int maxCrossSum = findMaxCrossingSum(arr, left, mid, right);
    
    return max(maxLeftSum, max(maxRightSum, maxCrossSum));
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Subarray Sum: " << maxSubArraySum(arr, 0, n - 1) << endl;
    return 0;
}
