class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]] += 1;
        }
        for(auto it:map){
            if(it.second > half){
                return it.first;
            }
        }
        return -1;
    }
};