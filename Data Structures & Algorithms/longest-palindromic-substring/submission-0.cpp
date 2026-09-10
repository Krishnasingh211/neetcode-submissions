#include <cstring>
class Solution {
public:
    int t[1001][1001];
    bool f(string &s,int i,int j){
        if(i>=j) return t[i][j]=1;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i]==s[j]){
            return t[i][j]=f(s,i+1,j-1);
        }
        else{
            return t[i][j]=0;
        }
    }

    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=0;
        memset(t,-1,sizeof(t));
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(s,i,j)==true){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
        
    }
};
