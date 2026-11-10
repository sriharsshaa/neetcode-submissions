class Solution {
public:
void solve(int r,int n,vector<bool> &col,vector<bool>& diag1,vector<bool>& diag2,vector<string>& board,vector<vector<string>>& ans){
    if(r==n){
        ans.push_back(board);return;
    }
    for(int i=0;i<n;i++){
        int d1=r+i;
        int d2=r-i+n-1;
        if(col[i] ||diag1[d1]||diag2[d2]) continue;
        board[r][i]='Q';
        col[i]=diag1[d1]=diag2[d2]=true;
        solve(r+1,n,col,diag1,diag2,board,ans);
        board[r][i]='.';
        col[i]=diag1[d1]=diag2[d2]=false;
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> col(n,false);
        vector<bool> diag1(2*n-1,false);
        vector<bool> diag2(2*n-1,false);
        vector<string> board(n,string(n,'.'));
        solve(0,n,col,diag1,diag2,board,ans);
        return ans;
    }
};
