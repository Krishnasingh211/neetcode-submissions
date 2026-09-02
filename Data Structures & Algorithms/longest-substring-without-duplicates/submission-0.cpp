class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        int i=0;int ans=0;
        unordered_map<char,int>mp;
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            while(i<j&&mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
