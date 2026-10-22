class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[left]<=nums[mid]) {
                if(nums[left]<=target && target<nums[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
            // Right half is sorted
            else{
                if(nums[mid]<target && target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};
/*

Algorithm
1. Initialize left = 0 and right = n - 1.
2. Calculate mid and check whether nums[mid] == target. If true, return mid.
3. Check which half is sorted:
   - If nums[left] <= nums[mid], the left half is sorted.
   - Otherwise, the right half is sorted.
4. Check whether the target lies within the sorted half's range.
5. If it does, search that half. Otherwise, eliminate that half and search the other one.
6. If the target is not found, return -1.

*/