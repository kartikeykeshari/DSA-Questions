class Solution {
public:
    int findMin(vector<int>& nums) {
       int n = nums.size();
       int low = 0;
       int high = n-1;
       if(n==1) return nums[0]; 
       if(nums[low] < nums[high]) return nums[low];
       while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            else if(nums[mid] < nums[mid-1]) return nums[mid];
            else{
                if(nums[mid] > nums[low]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        } 
        return -1;
    }
};