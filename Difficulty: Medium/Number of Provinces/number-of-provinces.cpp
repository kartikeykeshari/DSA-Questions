// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, int V){
        vis[node] = 1;
        
        for(int j=0; j<V; j++){
            if(adj[node][j] == 1 && !vis[j]){
                dfs(j, vis, adj, V);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int cnt = 0;
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj, V);
            }
        }
        return cnt;
    }
};