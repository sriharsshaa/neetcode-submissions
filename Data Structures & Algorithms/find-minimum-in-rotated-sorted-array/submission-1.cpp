class Solution {
public:
    int findMin(vector<int> &nums) {
        //Binary Search 
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        return nums[left];
    }
};
/*
return *min_element(nums.begin(),nums.end());
*/