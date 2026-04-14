// User function Template for C++
class Solution {
  private:
    void topoSort(int node, vector<int> &vis, vector<vector<pair<int, int>>>& adj, stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it.first]){
                topoSort(it.first, vis, adj, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        //find the topo sort 
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoSort(i, vis, adj, st);
            }
        }
        
        //do the distance thing
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] != 1e9 && dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        // Convert unreachable nodes to -1
        for(int i = 0; i < V; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};
