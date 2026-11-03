class Solution {
public:
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(vector<vector<char>>& grid,int m,int n, int i,int j){
    if(i<0|| j<0|| i>=m|| j>=n|| grid[i][j]!='1') return;
    grid[i][j]='0';
    for(int a=0;a<4;a++){
        int nx=i+d[a][0];
        int ny=j+d[a][1];
        dfs(grid,m,n,nx,ny);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    c++;
                    dfs(grid,m,n,i,j);
                }
            }
        }
        return c;
    }
};
