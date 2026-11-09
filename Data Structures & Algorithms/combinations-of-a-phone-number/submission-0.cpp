class Solution {
public:
vector<string> ans;
void solve(int i,string c,string digits,vector<string> mapp){
    if(i==digits.size()){
        ans.push_back(c);
        return;
    }
    string ll=mapp[digits[i]-'0'];
    for(char ch:ll){
        c.push_back(ch);
        solve(i+1,c,digits,mapp);
        c.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapp={
            "","","abc","def","ghi","jkl","mno","pqrs",
            "tuv","wxyz"
        };
        string c;
        solve(0,c,digits,mapp);
        return ans;
    }
};
