class Solution {
public:
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool dfs(vector<vector<char>>& board,string word,int m,int n,int i,int j, int id){
    if(id==word.size()) return true;
    if(i<0 || j<0|| i>=m|| j>=n ||board[i][j]!=word[id]) return false;
    char c=board[i][j];
    board[i][j]='0';
    for(int a=0;a<4;a++){
        int dx=i+d[a][0];
        int dy=j+d[a][1];
        if(dfs(board,word,m,n,dx,dy,id+1)) return true;
    }
    board[i][j]=c;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,m,n,i,j,0)) return true;
            }
        }
        return false;
    }
};
