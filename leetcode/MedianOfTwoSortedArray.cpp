#include <iostream>
#include <vector>

using namespace std; // Add this line to use the 'vector' class without explicitly specifying the namespace

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int sizeleft = nums1.size();
    int sizeRight = nums2.size();
    vector<int> nums3(sizeleft+sizeRight);
    int index=0,leftIndex=0,rightIndex=0;
    while(leftIndex<sizeleft && rightIndex< sizeRight){
        if(nums1[leftIndex]<nums2[rightIndex]){
            nums3[index++]=nums1[leftIndex++];
        }else{
            nums3[index++]=nums2[rightIndex++];
        }
    }
    while(leftIndex<sizeleft) {
        nums3[index++]=nums1[leftIndex++];
    }
    while(rightIndex<sizeRight) {
        nums3[index++]=nums2[rightIndex++];
    }

    if(nums3.size()%2==0){
        int mid1=nums3[nums3.size()/2];
        int mid2=nums3[(nums3.size()/2)-1];
        return (mid1+mid2)/2.0;
        
    }else{
        int i=(nums3.size()/2);
        return nums3[i];
    }
        
    }

int main(){
    vector<int> nums1 = {1, 3,5};
    vector<int> nums2 = {2,4,8};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}