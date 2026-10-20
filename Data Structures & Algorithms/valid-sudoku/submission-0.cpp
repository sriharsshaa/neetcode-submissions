class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char ch=board[i][j];
                board[i][j]='.';
                for(int x=0;x<9;x++){
                    if(board[i][x]==ch) return false;
                    if(board[x][j]==ch) return false;
                    if(board[3*(i/3)+(x/3)][3*(j/3)+(x%3)]==ch) return false;
                }
                board[i][j]=ch;
            }
        }
        return true;
    }
};
