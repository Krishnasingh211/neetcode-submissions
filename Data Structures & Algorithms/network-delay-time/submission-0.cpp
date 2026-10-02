class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,1e9);
        queue<pair<int,int>>q;
        q.push({k,0});
        dist[k]=0;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int dis=it.second;
            q.pop();
            for(auto &v:adj[node]){
                int ndis=v.second;
                int nn=v.first;
                if(dis+ndis<dist[nn]){
                    dist[nn]=dis+ndis;
                    q.push({nn,dis+ndis});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};