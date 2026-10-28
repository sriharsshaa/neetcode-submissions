class Solution {
public:
vector<vector<int>> ans;
void subs(vector<int>& nums,int i,vector<int>& curr){
    ans.push_back(curr);
    for(int j=i;j<nums.size();j++){
        if(j>i && nums[j]==nums[j-1]) continue;
        curr.push_back(nums[j]);
        subs(nums,j+1,curr);
        curr.pop_back();
    }    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        subs(nums,0,curr);
        return ans;
    }
};
