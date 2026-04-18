// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0) return -1;
        if(X == 0 && Y == 0) return 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0,0}});
        
        vector<vector<int>> dist(N, vector<int>(M, 1e9));
        dist[0][0] = 0;
        
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
                A[nrow][ncol] == 1 && d + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + d;
                    if(nrow == X && ncol == Y) return d + 1;
                    q.push({d+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};