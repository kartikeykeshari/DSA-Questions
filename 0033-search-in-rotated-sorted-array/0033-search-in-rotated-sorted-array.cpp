class Solution {
public:
    int minimumElement(vector<int>& nums){
        int n = nums.size();
        if(n==1) return 0;

        int low = 0;
        int high = n-1;

        if(nums[low] < nums[high]) return low;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid+1]) return mid+1;
            else if(nums[mid]<nums[mid-1]) return mid;
            else{
                if(nums[mid] > nums[low])
                {
                    low = mid+1;
                }
                else{
                    high = mid+1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low;
        int high;
        int ans = -1;

        int min = minimumElement(nums);
       

        low = 0;
        high = min-1;
        if(nums[min]==target) ans = min;

        while(low<=high){
            int m = (low+high)/2;
            if(nums[m] == target){
              ans = m;
              break;  
            } 
            else if(nums[m]>target) high = m-1;
            else low = m+1;
        }

        low = min+1;
        high = n-1;
        while(low<=high){
            int m = (low+high)/2;
            if(nums[m] == target){
              ans = m;
              break;  
            } 
            else if(nums[m]>target) high = m-1;
            else low = m+1;
        }
        return ans;
    }
};