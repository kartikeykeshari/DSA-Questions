class Solution {
public:
    int hammingWeight(int n) {
        //1st approch by using builtin function.
        return __builtin_popcount(n);

        // //2nd approch by using Brian Kernighan Algorithm
        // int count = 0;
        // while(n>0){
        //     count++;
        //     n = (n&(n-1));
        // }
        // return count;
    }
};