class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        int t=0;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int tm=it.second;
            q.pop();
            t=max(t,tm);
            for(int k=0;k<4;k++){
                int nr=row+r[k];
                int nc=col+c[k];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1&&vis[nr][nc]==0){
                    q.push({{nr,nc},tm+1});
                    vis[nr][nc]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&& vis[i][j]!=2) return -1;
            }
        }
        return t;
    }
};
