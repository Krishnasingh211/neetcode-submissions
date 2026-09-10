#include<cstring>
class Solution {
public:
    int n;  int t[1001][2001];
    int f(vector<int>&nums,int i,int pre){
        if(i>=n) return 0;
        if(t[i][pre+1000]!=-1) return t[i][pre+1000];
        int p=0;
        if(nums[i]>pre){
            p=1+f(nums,i+1,nums[i]);
        }
        int np=f(nums,i+1,pre);
        return t[i][pre+1000]=max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return f(nums,0,-1000);
        
    }
};
