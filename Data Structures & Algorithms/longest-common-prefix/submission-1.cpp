class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int i=0;
        string s1=strs[0];
        string s2=strs[strs.size()-1];
        while(i<s1.size() && i<s2.size() && s1[i]==s2[i]) i++;
        return s1.substr(0,i);
    }
};