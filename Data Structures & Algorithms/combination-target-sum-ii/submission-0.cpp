class Solution {
public:
vector<vector<int>> ans;
void subs(int ind,vector<int>& candidates,int target,vector<int>& curr){
    if(target==0){
        ans.push_back(curr); return;
    }
    for(int i=ind;i<candidates.size();i++){
        if(i>ind && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target) break;
        curr.push_back(candidates[i]);
        subs(i+1,candidates,target-candidates[i],curr);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        subs(0,candidates,target,curr);
        return ans;
    }
};
