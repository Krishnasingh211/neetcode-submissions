class Solution {
public:
    int n;
    
    int f(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(i>=n){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }

        } 
        if(dp[i][target+1000]!=-10000) return dp[i][target+1000];

        int t=f(i+1,nums,target-nums[i],dp);
        int nt=f(i+1,nums,target+nums[i],dp);
        return dp[i][target+1000]= t+nt;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2002,-10000));
        return f(0,nums,target,dp);
    }
};
