class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest=0;
        for(int n:st){
            if(st.find(n-1)==st.end()){
                int curr=n;
                int c=1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    c++;
                }
                longest=max(longest,c);
            }
        }
        return longest;
    }
};
