class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int s = rolls.size();
        int sum = mean*(n+s);
        for(int i=0;i<s;i++) {
            sum-=rolls[i];
        }
        if(sum<n || sum>6*n) return {};

        int avg = sum/n;
        int rem = sum%n;
        vector<int> ans(n,avg);
        for(int i=0;i<n;i++) {
            if(rem>0) {
                ans[i]++;
                rem--;
            }
        }
        return ans;
    }
};