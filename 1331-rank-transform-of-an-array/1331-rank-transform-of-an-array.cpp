class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> rankMap;
        int rank = 1;
        for(int i=0;i<n;i++){
            if(rankMap.find(temp[i]) == rankMap.end()){
                rankMap[temp[i]] = rank++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i] = rankMap[arr[i]];
        }
        return arr;
    }
};