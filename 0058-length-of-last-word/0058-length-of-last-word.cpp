class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int len = 0;
        int i = size-1;
        while(s[i] == ' '){
            i--;
        }
        while(i>=0 && s[i] != ' '){
            i--;
            len++;
        }
        return len;
    }
};