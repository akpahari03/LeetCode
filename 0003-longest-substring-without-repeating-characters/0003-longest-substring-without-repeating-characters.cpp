class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(s=="") return 0;
        vector<int> vis(256,-1);
        int l = 0;
        int r = 0;
        int maxi = INT_MIN;
        while(r<n) {
            if (vis[s[r]] != -1) l = max(vis[s[r]] + 1, l);

            vis[s[r]] = r;

            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};