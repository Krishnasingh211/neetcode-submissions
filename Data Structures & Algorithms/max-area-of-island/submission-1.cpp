class Solution {
public:
    int dfs(int i, int j,vector<vector<int>>& grid, vector<vector<int>>&vis){
        vis[i][j]=1; int m=grid.size();
        int n=grid[0].size();
        int ans=1;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+r[k];
            int nc=j+c[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0){
               ans=ans+ dfs(nr,nc,grid,vis);
            }
        }
        return ans;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=1 && grid[i][j]==1){
                   cnt=max(cnt, dfs(i,j,grid,vis));
                }
            }
        }
        return cnt;
    }
};
