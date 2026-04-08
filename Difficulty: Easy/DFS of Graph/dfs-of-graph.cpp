class Solution {
  public:
    void f(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                f(it, adj, vis, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        int st = 0;
        vis[0] = 1;
        vector<int> ans;
        f(st, adj, vis, ans);
        return ans;
    }
};