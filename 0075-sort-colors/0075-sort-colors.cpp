class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count1=0,count2=0,count3=0;
        for(int i=0;i<n;i++)
        {
            if(0==nums[i])
            count1++;
            else if(1==nums[i])
            count2++;
            else if(2==nums[i])
            count3++;
        }


        int nums2[300];
        for(int i=0;i<count1;i++)
        {
            nums2[i]=0;
            
        }
        for(int i=count1;i<count1+count2;i++)
        {
            nums2[i]=1;
        }
        for(int i=(count1+count2);i<count1+count2+count3;i++)
        {
            nums2[i]=2;
        }


        for(int i=0;i<n;i++)
        {
            nums[i] = nums2[i]; 
        }
    }
};