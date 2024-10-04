class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //Approch-1  Time complexity = O(nlogn)
        
        // if(s.size() != t.size()) return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // if(s == t) return true;
        // return false;


        // //Approch-2  Time complexity = O(n)

        // if(s.size() != t.size()) return false;

        // unordered_map<char,int> mp;
        // for(char ch:s){
        //     mp[ch]++;
        // }
        // for(char ch:t){
        //     if(mp[ch] == 0){
        //         return false;
        //     }
        //     mp[ch]--;
        // }
        // return true;


        //Using map - 3rd Approch
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int freq1 = mp1[ch];
            if(mp2.find(ch) != mp2.end()){
                int freq2 = mp2[ch];
                if(freq1 != freq2) return false;
            }
            else return false;
        }
        return true;
    }
};