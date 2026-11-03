class Solution {
public:
int d[8][2]={ {-1,-1}, {-1,0}, {-1,1},
            {0,-1},           {0,1},
            {1,-1},  {1,0},   {1,1}
        };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int steps=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto& [i,j]=q.front();
                q.pop();
                if(i==m-1 && j==n-1) return steps;
                for(int a=0;a<8;a++){
                    int nx=i+d[a][0];
                    int ny=j+d[a][1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};