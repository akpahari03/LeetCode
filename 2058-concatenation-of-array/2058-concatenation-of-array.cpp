class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int k=2;
        while(k>0) {
            for(int i=0;i<nums.size();i++) {
                ans.push_back(nums[i]);
            }
            k--;
        }
        return ans;
    }
};