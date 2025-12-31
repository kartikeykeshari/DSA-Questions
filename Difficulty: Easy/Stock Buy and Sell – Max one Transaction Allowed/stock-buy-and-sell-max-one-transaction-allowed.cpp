class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // int max = 0;
        // int n = prices.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(max <= prices[j]-prices[i]) max = prices[j]-prices[i];
        //     }
        // }
        // return max;
        
        
        int minP = INT_MAX;
        int maxP = 0;
        
        for(auto p : prices){
            minP = min(minP , p);
            maxP = max(maxP, p-minP);
        }
        return maxP;
    }
};
