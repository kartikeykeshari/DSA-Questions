class Solution {
  public:
    bool isPalinSent(string &s) {
        int flag = 0 ;
        
        // s.erase(remove(s.begin(), s.end(), ' '),s.end());
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            
            while(l<r && !isalnum(s[l])) l++;
            while(l<r && !isalnum(s[r])) r--;
            
            if(tolower(s[l]) != tolower(s[r])){
               flag = 1;
               break;
            } 
            l++; r--;
        }
        
        if(flag == 1) return false;
        
        return true;
    }
};