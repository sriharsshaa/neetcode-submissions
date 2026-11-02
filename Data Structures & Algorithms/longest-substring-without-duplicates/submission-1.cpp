class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l=0;
        int lon=0;
        for(int i=0;i<s.length();i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            lon=max(lon,i-l+1);
            st.insert(s[i]);
        }
        return lon;
    }
};


