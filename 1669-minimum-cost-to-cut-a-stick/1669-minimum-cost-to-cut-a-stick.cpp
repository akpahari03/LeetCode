class Solution {
public:
    int dp[102][102];
    int solve(vector<int>& cuts,int l,int r) {
        if(r-l<2) return 0;

        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        for(int i=l+1;i<=r-1;i++) {
            int cost = (cuts[r]-cuts[l]) + solve(cuts,l,i) + solve(cuts,i,r);
            ans = min(ans,cost);
        }
        dp[l][r] = ans;
        return dp[l][r];
    }
    int minCost(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        //memorization
        memset(dp,-1,sizeof(dp));

        return solve(cuts,0,cuts.size()-1);
    }
};