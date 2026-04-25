class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        vector<int> vis(V, 0);
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for(auto itr : adj[node]){
                int adjNode = itr.first;
                int edge_wt = itr.second;
                
                if(!vis[adjNode]){
                    pq.push({edge_wt, adjNode});
                }
            }
        }
        return sum;
    }
};