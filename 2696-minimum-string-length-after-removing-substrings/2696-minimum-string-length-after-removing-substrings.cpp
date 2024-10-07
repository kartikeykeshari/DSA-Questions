class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s.find("AB") != string::npos){
                int pos = s.find("AB");
                s.erase(pos,2);
            }
            else if(s.find("CD") != string::npos){
                int pos = s.find("CD");
                s.erase(pos,2);
            }
            else break;
        }
        return s.size();
    }
};