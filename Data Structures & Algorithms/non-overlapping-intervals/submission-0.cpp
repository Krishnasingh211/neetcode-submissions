class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(); 
        int ans=1;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int l=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=l){
                ans++;
                l=intervals[i][1];
            }

        }
        return n-ans;
    }
};
