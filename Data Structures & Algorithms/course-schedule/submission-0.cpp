class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ind(numCourses,0);
        vector<int>adj[numCourses];
        for(auto &it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            ind[u]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto v:adj[node]){
                ind[v]--;
                if(ind[v]==0){
                    q.push(v);
                }
            }
            
        }
        return ans.size()==numCourses;
    }
};
