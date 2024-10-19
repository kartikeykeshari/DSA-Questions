class Solution {
public:
    typedef pair<int,vector<int>> piv;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<piv> pq;
        for(auto v : points){
            int x = v[0] , y = v[1];
            int dis = x*x + y*y;
            piv p = {dis,v};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};