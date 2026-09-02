class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>sml(n);
        sml[0]=prices[0];
        for(int i=1;i<n;i++){
            sml[i]=min(sml[i-1],prices[i]);

        }
        vector<int>grt(n);
        grt[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            grt[i]=max(grt[i+1],prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,grt[i]-sml[i]);

        }
        return ans;
    }
};
