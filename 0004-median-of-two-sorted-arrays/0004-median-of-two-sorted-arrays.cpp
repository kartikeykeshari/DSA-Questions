class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m == 0 && n == 0) return 0;
        for(int i=0;i<n;i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int t_size = nums1.size();
        if(t_size % 2 != 0){
            int mid = t_size/2;
            double res = nums1[mid];
            return res;
        }
        else{
            int mid = t_size/2;
            double res = float(nums1[mid-1]+nums1[mid])/2;
            return res;
        }
    }
};