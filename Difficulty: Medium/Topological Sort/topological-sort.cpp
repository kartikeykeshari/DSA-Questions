class Solution {
  public:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        stack<int> st;
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};