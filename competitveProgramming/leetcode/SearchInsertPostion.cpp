#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        int lastIndex=nums.size()-1;
        int low=0,high=lastIndex,mid;

        if(nums[0]>target){
            return 0;
        }
        if(nums[lastIndex]<target){
            return lastIndex+1;
        }

        while(low<high){
            mid=(low+high)/2;

            if(nums[mid]==target){

                return mid;
            }
           else if(nums[mid-1]<target && nums[mid]>target){ // check nums[mid] also 

                return mid;
            }
           else if(nums[mid]<target && nums[mid+1]>target){ // check nums[mid] also 

                return mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
        }
    }
int main() {
    vector<int> nums = {1,3};
    int target = 2;
    cout << searchInsert(nums, target) << endl;

    // vector<int> nums1 = {1, 3, 4, 6, 9, 10};
    // int target1 = 8;
    // cout << searchInsert(nums1, target1) << endl; // Expected output: 4

    // vector<int> nums2 = {1, 3, 5, 6};
    // int target2 = 5;
    // cout << searchInsert(nums2, target2) << endl; // Expected output: 2

    // vector<int> nums3 = {1, 3, 5, 6};
    // int target3 = 2;
    // cout << searchInsert(nums3, target3) << endl; // Expected output: 1

    // vector<int> nums4 = {1, 3, 5, 6};
    // int target4 = 7;
    // cout << searchInsert(nums4, target4) << endl; // Expected output: 4

    // vector<int> nums5 = {1, 3, 5, 6};
    // int target5 = 0;
    // cout << searchInsert(nums5, target5) << endl; // Expected output: 0
    
    return 0;
}