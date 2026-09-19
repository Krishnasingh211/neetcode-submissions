class Solution {
public:
    void f(int i,vector<int>&ans){
        int c=0;
        while(i){
            c+=i&1;
            i>>=1;
        }
        ans.push_back(c);
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            f(i,ans);
        }
        return ans;
    }
};
