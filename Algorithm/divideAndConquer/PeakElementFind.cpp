#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Compare mid element with its right neighbor
        if (nums[mid] > nums[mid + 1]) {
            // A peak is on the left side (including mid)
            right = mid;
        } else {
            // A peak is on the right side
            left = mid + 1;
        }
    }

    // `left` and `right` converge to a peak
    return left;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = findPeakElement(nums);
    cout << "Peak element found at index: " << peakIndex << endl;
    cout << "Peak element is: " << nums[peakIndex] << endl;
    return 0;
}
