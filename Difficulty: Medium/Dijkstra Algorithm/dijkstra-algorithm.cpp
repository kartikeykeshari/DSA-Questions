class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;
        
        dist[src] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgeWeight = it.second;
                int edgeNode = it.first;
                
                if(dis + edgeWeight < dist[edgeNode]){
                    dist[edgeNode] = dis + edgeWeight;
                    pq.push({dist[edgeNode], edgeNode});
                }
            }
        }
        return dist;
        
    }
};