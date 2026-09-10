class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int preMax=nums[0];
        int preMin=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int x=nums[i];
            int cpreMax=max({x,x*preMax,x*preMin});
            int cpreMin=min({x,x*preMax,x*preMin});
            preMax=cpreMax;
            preMin=cpreMin;
            ans=max(ans,cpreMax);
        }
        return ans;
    }
};
