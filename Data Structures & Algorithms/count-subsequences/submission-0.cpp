#include <cstring>
class Solution {
public:
    int n,m;
    int p[1001][1001];
    int f(int i,int j,string &s, string &t){
        if(j>=m) return 1;
        if(i>=n) return 0;
        if(p[i][j]!=-1) return p[i][j];
        if(s[i]==t[j]){
            return p[i][j]= f(i+1,j+1,s,t)+f(i+1,j,s,t);
        }
        else{
            return p[i][j]= f(i+1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        n=s.length();
        m=t.length();
        memset(p,-1,sizeof(p));
        return f(0,0,s,t);
    }
};
