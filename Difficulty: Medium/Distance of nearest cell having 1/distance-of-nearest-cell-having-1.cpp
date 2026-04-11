class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // {{r, c}, s}
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
                else vis[i][j] = 0;
            }
        }
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int s = q.front().second;
            q.pop();
            dist[r][c] = s; 
            
            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, -1, 0, 1};
            
            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 ){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, s+1});
                }
            }
        }
        
        return dist;
        
    }
};