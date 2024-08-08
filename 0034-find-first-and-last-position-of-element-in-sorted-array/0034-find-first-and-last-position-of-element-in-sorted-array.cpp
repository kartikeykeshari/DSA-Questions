class Solution {
public:
    vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans1 = -1, ans2 = -1;

        // Find the first occurrence of the target
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
                if (nums[mid] == target) ans1 = mid;
            } else {
                low = mid + 1;
            }
        }

        low = 0;
        high = n - 1;

        // Find the last occurrence of the target
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
                if (nums[mid] == target) ans2 = mid;
            } else {
                high = mid - 1;
            }
        }

        // If the target was not found, return [-1, -1]
        if (ans1 == -1 || ans2 == -1) return {-1, -1};

        return {ans1, ans2};
    }
};