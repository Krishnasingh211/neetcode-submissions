#include<cstring>

class Solution {
public:
    int n;
    int t[301][5001];
    int f(vector<int>& coins,int i, int amount){
        if(amount==0) return 1;
        if(amount<0 ||i>=n) return 0;
        if(t[i][amount]!=-1) return t[i][amount];

        int take=f(coins,i,amount-coins[i]);
        int ntake=f(coins,i+1,amount);
        return t[i][amount]= (take+ntake);
    }

    int change(int amount, vector<int>& coins) {
       n=coins.size();
       memset(t,-1,sizeof(t));
       int x=f(coins,0,amount);
       return x;
    }
};