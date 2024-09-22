class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        int st = 0, end = 0;
        //For odd length
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l >= 0 && r<n){
                if(s[l] == s[r]){
                    l--;r++;
                }
                else{
                    break;
                }
            }
            int len = r-l-1;
            if(maxlen < len){
                maxlen = len;
                st = l+1;
                end = r-1;
            }
        }

        //For even length
        for(int i=0;i<n;i++){
            int l=i,r=i+1;
            while(l >=0 && r<n){
                if(s[l] == s[r]){
                    l--;r++;
                }
                else{
                    break;
                }
            }
            int len = r-l-1;
            if(maxlen < len){
                maxlen = len;
                st = l+1;
                end = r-1;
            }
        }

        return s.substr(st,maxlen);
    }
};