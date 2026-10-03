class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        vector<int>vis(n,0);
        int sum=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int dis=it.first;
            pq.pop();
            
            if(vis[node])
                continue;
            vis[node]=1;
            sum+=dis;
            for(auto v:adj[node]){
                int nn=v.first;
                int nwt=v.second;
                if(vis[nn]==0){
                    pq.push({nwt,nn});
                }
            }
        }
        return sum;
    }
};