class Solution {
public:
    char repeatedCharacter(string s) {
        bool isSeen[26] = {false};
        for(int i=0;i<s.length();i++) {
            int idx = s[i] - 'a';
            if(isSeen[idx]) return s[i];
            isSeen[idx] = true;
        }
        return 0;
    }
};