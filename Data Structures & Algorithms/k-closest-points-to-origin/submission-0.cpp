class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int>x; vector<pair<int,pair<int,int>>>ans;
        for(auto &it:points){
            int q=it[0];
            int r=it[1];
            long long a = 1LL*q*q + 1LL*r*r;
            ans.push_back({a,{q,r}});
        }
        int n=ans.size();
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<k;i++){
            q.push({ans[i].first,{ans[i].second.first,ans[i].second.second}});
        }
        for(int i=k;i<n;i++){
            if(ans[i].first<=q.top().first){
                q.pop();
                q.push({ans[i].first,{ans[i].second.first,ans[i].second.second}});
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<k;i++){
            res.push_back({q.top().second.first,q.top().second.second});
            q.pop();
        }
        return res;
    }
};
