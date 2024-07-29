class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                temp1.push_back(nums[i]);
            }
            else{
                temp2.push_back(nums[i]);
            }
        }
        int p_index = 0;
        int n_index = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0 && p_index < nums.size()){
                nums[i] = temp1[p_index++];
            }
            else if(n_index < nums.size()){
                nums[i] = temp2[n_index++];
            }
        }
        return nums;
    }
};