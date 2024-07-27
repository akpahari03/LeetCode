class Solution {
public:
    //TC:O(n) SC:O(1)
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            int num=abs(nums[i]);
            int index=num-1;

            if(nums[index]<0) ans.push_back(num);
            else nums[index] *= -1;
        }
        return ans;

    }
};