class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> temp(numRows);
        for(int i=0;i<numRows;i++){
           temp[i].resize(i+1);

            for(int j=0;j<=i;j++){

                if(j==0 || j==i){
                    temp[i][j] = 1;
                }

                else{
                    temp[i][j] = temp[i-1][j-1] + temp[i-1][j];
                }
            }
        }
        return temp;
    }
};