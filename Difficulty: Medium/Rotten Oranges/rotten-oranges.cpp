class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        //{{r, c}, t}
        queue<pair<pair<int,int>, int>> q;
        int vis[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j}, 0});
                }
                else vis[i][j] = 0;
            }
        }
        
        int maxtime = 0;
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            maxtime = max(maxtime, t);
            q.pop();
            
            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                mat[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return maxtime;
        
    }
};