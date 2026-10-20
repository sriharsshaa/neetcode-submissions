class Solution {
public:
/*
Steps:
    1. Initialize left = 0, maxFreq = 0, and longest = 0.
    2. Move right through the string, expanding the window.
    3. Count the frequency of s[right] and update maxFreq.
    4. If window len-maxFreq>k, shrink the window by moving left forward.
    5. Update the longest valid window length.
    6. Return longest.
*/
    int characterReplacement(string s, int k) {
        int left=0, mf=0, longest=0;
        unordered_map<char,int> mp;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            mf=max(mf,mp[s[r]]);
            while((r-left+1)-mf>k){
                mp[s[left]]--;
                left++;
            }
            longest=max(longest,r-left +1);
        }
        return longest;
    }
};
