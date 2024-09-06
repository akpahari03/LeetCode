class Solution {
public:
    int kadaneMax(vector<int>& nums,int n) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            maxi = max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
    int kadaneMin(vector<int>& nums,int n) {
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            mini = min(mini,sum);
            if(sum>0) sum=0;
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int minSum = kadaneMin(nums,n);
        int maxSum = kadaneMax(nums,n);
        int circularSum = totalSum - minSum;

        if(maxSum>0) return max(maxSum,circularSum);
        return maxSum;
    }
};