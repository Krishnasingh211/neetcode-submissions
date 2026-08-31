class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>f(26);
        int n=s.length();
        if(t.length()!=n) return false;
        for(int i=0;i<n;i++){
            f[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            if(f[t[i]-'a']==0) return false;
            f[t[i]-'a']--;
        }
        return true;
    }
};
