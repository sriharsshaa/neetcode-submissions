class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        bool odd=false;
        for(int a:s) mp[a]++;
        int c=0;
        for(auto& it:mp){
            if(it.second%2==0) c+=it.second;
            else{
                c+=it.second-1;
                odd=true;
            }
        }
        if(odd) c++;
        return c;
    }
};