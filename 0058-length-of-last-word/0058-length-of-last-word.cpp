class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i] != ' ') count++;
            if(s[i]==' ' && count!=0) break;
        }
        return count;
    }
};