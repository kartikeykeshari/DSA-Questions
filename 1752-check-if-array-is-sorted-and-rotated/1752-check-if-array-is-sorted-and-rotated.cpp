class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Count the number of times the array is out of order
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // If the array is sorted or can be sorted by a single rotation, count should be <= 1
        return count <= 1;
    }
};