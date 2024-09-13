class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr;
        int i=0;
        int xorr=0;
        while(i<n) {
            int ans=start+2*i;
            arr.push_back(ans);
            xorr=xorr^ans;
            i+=1;
        }
        return xorr;

    }
};