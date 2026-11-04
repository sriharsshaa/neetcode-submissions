class Solution {
public:
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(vector<vector<int>>& image, int i,int j,int old,int color){
    int n=image.size();
    int m=image[0].size();
    if(i<0 || j<0|| i>=n|| j>=m|| image[i][j]!=old) return;
    image[i][j]=color;
    for(int a=0;a<4;a++){
        int nx=i+d[a][0];
        int ny=j+d[a][1];
        dfs(image,nx,ny,old,color);
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        if(old==color) return image;
        dfs(image,sr,sc,old,color);
        return image;
    }
};