class Solution {
public:
    int solve(vector<int>& nums,int start,int end) {
        int prevMax = 0;
        int currMax = 0;
        for(int i=start;i<=end;i++) {
            int temp = max(nums[i]+prevMax,currMax);
            prevMax = currMax;
            currMax = temp;
        }
        return currMax;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};