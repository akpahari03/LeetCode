class Solution {
public:
    int maxScore(string s) {
        int maxi = INT_MIN;
        int n = s.length();
        for(int i=0;i<n-1;i++) {
            int zero = 0;
            int one = 0;
            for(int j=0;j<=i;j++) {
                if(s[j]=='0') zero++;
            }
            for(int k=i+1;k<n;k++) {
                if(s[k]=='1') one++;
            }
            maxi = max(maxi,zero+one);
        }
        return maxi;
    }
};