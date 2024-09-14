class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = 0;
        int ans = 0;
        int steps = 0;
        for(int num : nums) {
            if(num>maxValue) {
                maxValue = num;
                steps = 0;
                ans = 0;
            }
            if(num==maxValue) {
                steps++;
            } else steps = 0;
            ans = max(ans,steps);
        }
        return ans;
    }
};