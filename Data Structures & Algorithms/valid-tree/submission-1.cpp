class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                vis[i]=1;
                queue<pair<int,int>>q;
                q.push({i,-1});
                while(!q.empty()){
                    auto it=q.front();
                    q.pop();
                    int node=it.first;
                    int parent=it.second;
                    for(auto &v:adj[node]){
                        if(vis[v]==0){
                            vis[v]=1;
                            q.push({v,node});
                        }
                        else if(parent!=v){
                            return false;
                        }
                    }
                }
            }
        }
        if(cnt>1) return false;
        return true;

    }
};
