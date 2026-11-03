class Solution {
public:
    string minWindow(string s, string t) {
        int st=0;
        int l=0;
        int minx=INT_MAX;
        unordered_map<char,int> mp;
        for(char c:t) mp[c]++;
        int req=t.size();
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0) req--;
            mp[s[i]]--;
            while(req==0){
                if(i-l+1<minx){
                    minx=i-l+1;
                    st=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) req++;
                l++;
            }
        }
        if(minx==INT_MAX) return "";
        return s.substr(st,minx);
    }
};

