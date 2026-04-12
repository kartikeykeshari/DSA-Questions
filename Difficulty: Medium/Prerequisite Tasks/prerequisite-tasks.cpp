class Solution {
  public:
    bool isPossible(int V, int P, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto it : prerequisites){
            adj[it.first].push_back(it.second);
        }
        
        vector<int> indegree(V);
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(topo.size() == V) return true;
        else return false;
        
    }
};