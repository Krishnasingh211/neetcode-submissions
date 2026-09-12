class Solution {
public:
    int n,m;
    
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,vector<vector<int>>&vis){
        if(i>=m || j>=n ||i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res1=1;
        if(i+1<m && matrix[i+1][j]>matrix[i][j]&&vis[i+1][j]==0){
            vis[i+1][j]=1;
            res1=1+f(i+1,j,matrix,dp,vis);
            vis[i+1][j]=0;
        }
        int res2=1;
        if(j+1<n && matrix[i][j+1]>matrix[i][j]&&vis[i][j+1]==0){
            vis[i][j+1]=1;
            res2=1+f(i,j+1,matrix,dp,vis);
            vis[i][j+1]=0;
        }
        
        int res3=1;
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]&&vis[i][j-1]==0){
            vis[i][j-1]=1;
            res3=1+f(i,j-1,matrix,dp,vis);
            vis[i][j-1]=0;
        }
        int res4=1;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]&&vis[i-1][j]==0){
            vis[i-1][j]=1;
            res4=1+f(i-1,j,matrix,dp,vis);
            vis[i-1][j]=0;
        }
        return dp[i][j]=max({res1,res2,res3,res4});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               ans=max(ans,f(i,j,matrix,dp,vis));
            }
        }
      return ans;
        
    }
};