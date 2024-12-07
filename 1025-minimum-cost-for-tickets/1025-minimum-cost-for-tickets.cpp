class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int index,vector<int>& dp) {
        int n = days.size();
        if(index>=n) return 0;

        if(dp[index]!=-1) return dp[index];
        //1 day pass
        int op1 = costs[0] + solve(days,costs,index+1,dp);

        //7 days pass
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++);
        int op2 = costs[1] + solve(days,costs,i,dp);

        //30 days pass
        for(i=index;i<n && days[i]<days[index]+30;i++);
        int op3 = costs[2] + solve(days,costs,i,dp);

        dp[index] = min(op1,min(op2,op3));
        return dp[index];

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size()+1,-1);
        // return solve(days,costs,0,dp);

        //Space Optimised
        int ans = 0;
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;

        for(int day : days) {
            while(!month.empty() && month.front().first + 30 <= day) month.pop();
            while(!week.empty() && week.front().first + 7 <= day) week.pop();

            week.push(make_pair(day,ans+costs[1]));
            month.push(make_pair(day,ans+costs[2]));

            ans = min(ans+costs[0],min(week.front().second,month.front().second));
        }
        return ans;
    }
};