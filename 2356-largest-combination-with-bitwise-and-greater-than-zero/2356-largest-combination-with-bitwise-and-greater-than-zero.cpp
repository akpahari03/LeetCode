class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int maxi = 0;
        for(int bitpos=0;bitpos<32;bitpos++) {
            int count = 0;
            for(int &num : candidates) {
                if((num&(1<<bitpos))!=0) count++;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};