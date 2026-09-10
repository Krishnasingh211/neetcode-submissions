class Solution {
public:
    int f(vector<int>&nums,int i,vector<int>&dp,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+f(nums,i+2,dp,n);  
        int npick=0;
        if(i+1<n)
         npick=nums[i+1]+f(nums,i+3,dp,n);
        return dp[i]=max(pick,npick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1)
            return nums[0];
        vector<int>dp(n,-1);
        int m=f(nums,0,dp,n-1);
        vector<int>dp1(n,-1);
        int c=f(nums,1,dp1,n);
        return max(m,c);
        
    }
};
