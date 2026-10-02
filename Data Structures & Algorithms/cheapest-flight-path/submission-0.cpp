class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});

        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stops>k) continue;
            for(auto v:adj[node]){
                int nn=v.first;
                int nd=v.second;
                if(nd+dis<dist[nn]){
                    dist[nn]=nd+dis;
                    q.push({stops+1,{nn,dis+nd}});
                }
            }
        }
        return dist[dst]==1e9?-1:  dist[dst];
    }
};