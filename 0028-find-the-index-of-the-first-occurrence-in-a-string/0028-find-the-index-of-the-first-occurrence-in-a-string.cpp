class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = needle.size();
        int y = haystack.size();
        if(x > y) return -1;
        for(int i=0; i<=y-x; i++){
            string s = haystack.substr(i,x);
            if(s == needle){
                return i;
            }
        }
        return -1;
    }
};