class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        int k = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                temp[k++] = nums[i];
            }
        }
        while(n-k){
            temp[k++] = 0;
        }
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
    }
};