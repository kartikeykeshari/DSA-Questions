class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            if(nums[low] == target) return true;
            if(nums[low] == nums[high]){
                low++;
                high--;
            }
            else{
                break;
            }
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return true;
            if(nums[mid] >= nums[low]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(target <= nums[high] && target >= nums[mid]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};