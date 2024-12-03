class Solution {
public:
    void findCombination(int idx,vector<int>& arr, int target,vector<vector<int>> &ans,vector<int> &ds) {
        if(idx==arr.size()) {
            if(target==0) ans.push_back(ds);
            return;
        }
        if(arr[idx]<=target) {
            ds.push_back(arr[idx]);
            findCombination(idx,arr,target-arr[idx],ans,ds);
            ds.pop_back();
        }
        findCombination(idx+1,arr,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,candidates,target,ans,ds);
        return ans;
    }
};