class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prevMax = 0; 
        int currMax = 0; 
        for (int i = 0; i < n; i++) {
            int temp = max(nums[i] + prevMax, currMax);
            prevMax = currMax;
            currMax = temp;
        }
        return currMax;
    }
};