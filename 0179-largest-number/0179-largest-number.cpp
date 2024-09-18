class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto myComparator = [](int &a , int &b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            if(s1+s2 > s2+s2) return true;
            return false;
        };
        sort(nums.begin(),nums.end(),myComparator);

        if(nums[0]==0) return "0";
        string ans = "";
        for(auto &s : nums) {
            ans += to_string(s);
        }
        return ans;
    }
};