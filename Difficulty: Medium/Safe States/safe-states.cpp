class Solution {
  public:
    bool dfs(int node, vector<int> &vis, vector<int>& pathvis, vector<vector<int>> &adj,
    vector<int> &check){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathvis, adj, check)){
                    // pathvis[node] = 0;
                    check[it] = 0;
                    return true;  
                } 
            }
            else if(pathvis[it]){
                // pathvis[node] = 0;
                check[it] = 0;
                return true;
            } 
        }
        
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<int> check(V, 0);
        
        vector<vector<int>> adj(V);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v); // directed
        }
        
        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, adj, check);
            }
        }
        
        for(int i=0; i<V; i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};