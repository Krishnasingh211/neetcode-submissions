class Solution {
public:
    int f(vector<int>&cost,int i,vector<int>&dp){
        if(i>cost.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int p=cost[i]+f(cost,i+1,dp);
        int pp=cost[i]+f(cost,i+2,dp);
        return dp[i]=min(p,pp);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int x=f(cost,0,dp);
        vector<int>d(n,-1);
        int y=f(cost,1,d);
        return min(x,y);
        
    }
};