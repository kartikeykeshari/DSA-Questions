class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, 
    int newColor, vector<int> &delrow, vector<int> &delcol, int &initColor){
        
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            ans[nrow][ncol] == initColor && ans[nrow][ncol] != newColor){
                
                dfs(nrow, ncol, image, ans, newColor, delrow, delcol, initColor);
            }
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int initColor = image[sr][sc];
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        vector<vector<int>> ans = image;
        dfs(sr, sc, image, ans, newColor, delrow, delcol, initColor);
        return ans;
    }
};