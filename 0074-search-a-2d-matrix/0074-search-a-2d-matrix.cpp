class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int totalEle = m*n;
        int low = 0;
        int high = totalEle-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            }
            else if(matrix[mid/n][mid%n] <  target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};