class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        int m = queries[0].size();
        for(int i=0;i<n;i++) {
            int num1 = queries[i][0];
            int num2 = queries[i][1];
            int temp = 0;
            for(int i=num1;i<=num2;i++) {
                temp = temp ^ arr[i];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};