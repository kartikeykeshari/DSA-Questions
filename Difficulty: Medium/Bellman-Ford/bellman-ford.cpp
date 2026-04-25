// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i=0; i<V-1; i++){
            for(auto it : edges){
                if(dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]]){
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }
        
        //Nth relaxation to check the -ve cycle
        for(auto it : edges){
            if(dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]]){
                return {-1};
            }
        }
        return dist;
    }
};
