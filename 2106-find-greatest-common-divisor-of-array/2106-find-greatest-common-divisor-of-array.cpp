class Solution {
public:
    int gcd(int mini , int maxi) {
        int result = min(mini,maxi);
        while(result > 0) {
            if(mini % result == 0 && maxi % result == 0) break;
            result--;
        }
        return result;
    }
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        return gcd(mini,maxi);
    }
};