class Solution {
public:
vector<vector<string>> ans;
bool isPalin(string s,int st,int end){
    while(st<=end){
        if(s[st++]!=s[end--]) return false;
    }
    return true;
}
void solve(string s, int ind,vector<string> path,int n){
    if(ind==n){
        ans.push_back(path);return;
    }
    for(int i=ind;i<n;i++){
        if(isPalin(s,ind,i)){
            path.push_back(s.substr(ind,i-ind+1));
            solve(s,i+1,path,n);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> path;
        solve(s,0,path,n);
        return ans;
    }
};
