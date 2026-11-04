class Solution {
public:
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(vector<vector<int>>& grid,int i,int j,int m, int n){
    if(i<0|| j<0|| i>=m|| j>=n|| grid[i][j]==0) return 0;
    grid[i][j]=0;
    int area=1;
    for(int a=0;a<4;a++){
        int nx=i+d[a][0];
        int ny=j+d[a][1];
        area+=dfs(grid,nx,ny,m,n);
    }
    return area;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j,m,n);
                    mx=max(mx,area);
                }
            }
        }
        return mx;
    }
};
