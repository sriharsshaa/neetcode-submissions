class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c:t) mp[c]++;
        int minx=INT_MAX;
        int req=t.size();
        int l=0;
        int st=0;
        for(int r=0;r<s.size();r++){
            if(mp[s[r]]>0) req--;
            mp[s[r]]--;
            while(req==0){
                if(r-l+1<minx){
                    minx=r-l+1;
                    st=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) req++;
                l++;
            }
        }
        if(minx==INT_MAX) return "";
        return s.substr(st, minx);
    }
};
