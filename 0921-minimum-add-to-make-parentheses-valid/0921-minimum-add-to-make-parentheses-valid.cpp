class Solution {
public:
    
    // here we will check for this (),and calculate in how many attempts will have to make like it.
    int minAddToMakeValid(string s) {
        int l = 0;
        int r = 0;
        for(char it: s){
            if(it == '(') l++;
            else{
                if(l == 0) r++;
                else l--;
            }
        }
        return l+r;
    }
};