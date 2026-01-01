class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        map<int,int> mp;
        
        for(auto t : arr){
            mp[t]++;
        }
        vector<int> ans;
        for(auto t : mp ){
            ans.push_back(t.first);
        }
        
        return ans;
    }
};