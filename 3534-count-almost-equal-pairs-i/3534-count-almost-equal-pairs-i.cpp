class Solution {
private:
    bool isAlmostEqual(int x, int y) {
        string s1 = to_string(x);
        string s2 = to_string(y);
        while (s1.length() < s2.length()) {
            s1 = "0" + s1;
        }
        while (s2.length() < s1.length()) {
            s2 = "0" + s2;
        }

        int diffCount = 0;
        vector<int> diffIndex;
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffCount++;
                diffIndex.push_back(i);
                if (diffCount > 2) {
                    return false;
                }
            }
        }
        
        if (diffCount == 0) {
            return true;
        }
        if (diffCount == 2) {
            string s1Array = s1;
            int idx1 = diffIndex[0];
            int idx2 = diffIndex[1];
            swap(s1Array[idx1], s1Array[idx2]);

            return s1Array == s2;
        }
        
        return false;
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isAlmostEqual(nums[i], nums[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};