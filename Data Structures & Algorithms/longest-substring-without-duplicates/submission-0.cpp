class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int left=0;
        int longg=0;
        for(int r=0;r<s.length();r++){
            while(mp.find(s[r])!=mp.end()){
                mp.erase(s[left]);left++;
            }
            mp.insert(s[r]);
            longg=max(longg,r-left+1);
        }
        return longg;
    }
};
