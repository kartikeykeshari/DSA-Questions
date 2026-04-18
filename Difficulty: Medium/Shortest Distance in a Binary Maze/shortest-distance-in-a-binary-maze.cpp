// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        // if(grid[source.first][source.second] == 0) return -1;
        if(destination.first == source.first && destination.second == source.second) return 0;
        
        int N = grid.size();
        int M = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first,source.second}});
        
        vector<vector<int>> dist(N, vector<int>(M, 1e9));
        dist[source.first][source.second] = 0;
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0; i<4; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M &&
                grid[nrow][ncol] == 1 && d + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + d;
                    if(nrow == destination.first && ncol == destination.second) return d + 1;
                    q.push({d+1, {nrow, ncol}});
                }
            }
        }
        return -1;
        
    }
};
