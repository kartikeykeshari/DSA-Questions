class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vs(n, 0);
        int node = 0;
        vs[node] = 1;
        queue<int> q;
        q.push(node);
        vector<int> ans;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto it : adj[curr]){
                if(!vs[it]){
                    vs[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};