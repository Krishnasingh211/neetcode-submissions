class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<vector<int>>&adj){
        vis[i]=1;
        for(auto v:adj[i]){
            if(vis[v]==0){
                dfs(v,vis,adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
