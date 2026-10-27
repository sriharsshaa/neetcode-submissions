class Solution {
public:
vector<vector<int>> ans;
void subs(vector<int>& nums,int sum,int i,vector<int>& curr,int target){
    if(sum==target){
        ans.push_back(curr);return;
    }
    if(i==nums.size() || sum>target) return;
    curr.push_back(nums[i]);
    subs(nums,nums[i]+sum,i,curr,target);
    curr.pop_back();
    subs(nums,sum,i+1,curr,target);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        subs(nums,0,0,curr,target);
        return ans;
    }
};
