#include <cstring>
class Solution {
public:
int n;
    int t[303][303];
    int f(int l,int r,vector<int>&nums){
        if(l+1==r) return 0;
        if(t[l][r]!=-1) return t[l][r];
        int ans=0;
        for(int k=l+1;k<r;k++){
            int x=(nums[l]*nums[k]*nums[r]+f(l,k,nums)+f(k,r,nums));
            ans=max(ans,x);
        }
        return t[l][r]= ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,n-1,nums);
        
    }
};