class Solution {
public:
    string longestPalindrome(string s) {
        int mx=0;
        int st=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(mx<r-l+1){
                    st=l;
                    mx=r-l+1;
                }
                l--;r++;
            }
            l=i;r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(mx<r-l+1){
                    st=l;mx=r-l+1;
                }
                l--;r++;
            }
        }
        return s.substr(st,mx);
    }
};
