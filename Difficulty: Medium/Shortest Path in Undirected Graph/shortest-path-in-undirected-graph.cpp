class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(wt+1 < dist[it]){
                    dist[it] = wt+1;
                    q.push({it, wt+1});
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
