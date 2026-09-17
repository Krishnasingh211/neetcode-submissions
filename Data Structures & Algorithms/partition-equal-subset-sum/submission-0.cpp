class Solution {
public: int n;
    
    int f(int i,vector<int>&nums,vector<vector<int>>&dp,int sum){
        if(i>=n){
            if(sum==0) return 1;
            else{
                return 0;
            }
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nt=f(i+1,nums,dp,sum);
        int take=0;
        if(sum>=nums[i])
          take=f(i+1,nums,dp,sum-nums[i]);
        return dp[i][sum]= nt+take;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0; n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
        return f(0,nums,dp,sum/2);
        
    }
};
