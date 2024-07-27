class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber) {
            columnNumber--;
            int remainder=columnNumber%26;
            ans+=remainder+'A';
            columnNumber /=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};