class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'I' && s[i+1] != 'V' && s[i+1] != 'X'){
                sum += 1;
            }
            else if(s[i] == 'I' && s[i+1] == 'V' && s[i+1] != 'X'){
                sum += 4;
                i++;
            }
            else if (s[i] == 'I' && s[i+1] == 'X'){
                sum += 9;
                i++;
            }

            else if(s[i] == 'X' && s[i+1] != 'L' && s[i+1] != 'C'){
                sum += 10;
            }
            else if(s[i] == 'X' && s[i+1] == 'L' && s[i+1] != 'C'){
                sum += 40;
                i++;
            }
            else if (s[i] == 'X' && s[i+1] == 'C'){
                sum += 90;
                i++;
            }


            else if(s[i] == 'C' && s[i+1] != 'D' && s[i+1] != 'M'){
                sum += 100;
            }
            else if(s[i] == 'C' && s[i+1] == 'D' && s[i+1] != 'M'){
                sum += 400;
                i++;
            }
            else if (s[i] == 'C' && s[i+1] == 'M'){
                sum += 900;
                i++;
            }

            else if(s[i] == 'V'){
                sum += 5;
            }
            else if(s[i] == 'L')
            {
                sum += 50;
            }
            else if(s[i] == 'D'){
                sum += 500;
            }
            else if(s[i] == 'M'){
                sum += 1000;
            }
        }

        return sum;
    }
};