class Solution {
public:
    void solve(int idx,int sum,int n,vector<vector<int>>& ans,vector<int>& temp,int k) {
        if(sum==n && k==0) {
            ans.push_back(temp);
            return;
        }
        if(sum>n) return;
        for(int i=idx;i<=9;i++) {
            if(i>n) break;
            temp.push_back(i);
            solve(i+1,sum+i,n,ans,temp,k-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1,0,n,ans,temp,k);
        return ans;
    }
};