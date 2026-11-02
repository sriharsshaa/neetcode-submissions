class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int f=n/2;
        unordered_map<int,int> mp;
        for(int c:nums) mp[c]++;
        for(auto& it:mp){
            if(it.second>f) return it.first;
        }
    }
};