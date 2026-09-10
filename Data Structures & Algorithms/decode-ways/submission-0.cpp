#include<cstring>
class Solution {
public:
    int n;
    int t[101];
    
    int f(string &s,int i){
        if(i==n) return t[i]= 1;
        if(t[i]!=-1) return t[i];
        
        if(s[i]=='0') return t[i]= 0;
        int result=f(s,i+1);
        if(i+1<n&&(s[i]=='1'||s[i]=='2'&&s[i+1]<='6')){
            result+=f(s,i+2);
        }
        return t[i]= result;
    }

    int numDecodings(string s) {
        n=s.length();
        memset(t,-1,sizeof(t));
        return f(s,0);
        
    }
};