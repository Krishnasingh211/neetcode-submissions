class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>res(2);int i=0;
        while(i<n){
          while(i<n-1 && intervals[i][1]>=intervals[i+1][0]){
            intervals[i+1][0]=min(intervals[i][0],intervals[i+1][0]);
            intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
            i++;
          }
          ans.push_back(intervals[i]);
          i++;
        }
        return ans;
    }
};
