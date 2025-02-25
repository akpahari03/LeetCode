class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;
        int rows = accounts.size();
        int cols = accounts[0].size();
        for(int i=0;i<rows;i++) {
            int sum = 0;
            for(int j=0;j<cols;j++) {
                sum += accounts[i][j];
            }
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};