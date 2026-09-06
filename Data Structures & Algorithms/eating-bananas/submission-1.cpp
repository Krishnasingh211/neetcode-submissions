class Solution {
public:
    int f(vector<int>&piles,int k){
        int n=piles.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=((piles[i]+k-1)/k);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int mini=1;
        int maxi=*max_element(piles.begin(),piles.end());
        int ans=maxi;
        while(mini<=maxi){
            int mid=(maxi+mini)/2;
            int n=f(piles,mid);
            if(n>h){
                mini=mid+1;
                
            }
            else{
                maxi=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};
