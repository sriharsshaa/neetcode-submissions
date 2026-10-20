class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        for(auto &f:mp){
            if(f.second>1) return true;
        }
        return false;
    }
};