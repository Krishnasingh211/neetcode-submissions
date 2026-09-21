class Solution {
public:
    int m,n;
    
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+r[k];
            int nc=j+c[k];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&vis[nr][nc]==0&&grid[i][j]=='1'){
                dfs(nr,nc,vis,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
