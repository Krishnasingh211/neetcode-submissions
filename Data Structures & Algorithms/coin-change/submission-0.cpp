#include<cstring>
class Solution {
public:
    int n;
    int t[11][10001];
    int f(vector<int>& coins,int i, int amount){
        if(amount==0) return 0;
        if(amount<0 ||i>=n) return 1e9;
        if(t[i][amount]!=-1) return t[i][amount];

        int take=1+f(coins,i,amount-coins[i]);
        int ntake=f(coins,i+1,amount);
        return t[i][amount]= min(take,ntake);
    }


    int coinChange(vector<int>& coins, int amount) {
       n=coins.size();
       memset(t,-1,sizeof(t));
       int x=f(coins,0,amount);
       return x==1e9 ?-1:x;
        
    }
};
