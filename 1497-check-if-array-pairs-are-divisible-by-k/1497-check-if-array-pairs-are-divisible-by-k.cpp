class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> rem_count(k,0);
        for(int num : arr){
            int rem = ((num%k)+k)%k;  //it will also handle negative elements
            rem_count[rem]++;
        }
        if(rem_count[0]%2 != 0) return false;
        for(int i=1;i<k;i++){
            if(rem_count[i] != rem_count[k-i]) return false;
        }
        return true;
    }
};