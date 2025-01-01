class Solution {
public:
    int maxScore(string s) {
        int maxi = INT_MIN;
        int n = s.length();
        int total_ones = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') total_ones++;
        }
        //int total_ones = count(begin(s), end(s), '1');  can be written in this form also
        
        int left_zeros = 0;
        int left_ones = 0;
        for(int i=0;i<n-1;i++) {
            if(s[i]=='0') left_zeros++;
            else left_ones++;
            int right_ones = total_ones-left_ones;
            maxi = max(maxi,left_zeros+right_ones);
        }
        return maxi;
    }
};