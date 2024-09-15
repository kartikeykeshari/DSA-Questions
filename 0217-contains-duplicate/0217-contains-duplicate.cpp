class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n == 1) return false;
        if(nums[0] == nums[1]) return true;
        if(nums[n-1] == nums[n-2]) return true;
        for(int i=1;i<n-1;i++){
            if(nums[i] == nums[i-1] || nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};