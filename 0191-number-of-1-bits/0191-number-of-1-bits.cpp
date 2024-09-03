class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n>0 || n>1) {
            int temp = n%2;
            if(temp) ans++;
            n/=2;
        }
        return ans;
    }
};