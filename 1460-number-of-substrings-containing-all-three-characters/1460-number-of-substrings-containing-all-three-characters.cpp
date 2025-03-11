class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> temp(3,0);

        int i = 0;
        int j = 0;
        while(j<n) {
            char ch = s[j];
            temp[ch-'a']++;
            while(temp[0] > 0 && temp[1] > 0 && temp[2] > 0) {
                ans += (n-j);
                temp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};