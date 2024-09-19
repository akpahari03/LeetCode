class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int left = 0;
        int right = min(k,n);
        while(left < n) {
            reverse(s.begin()+left,s.begin()+right);
            left += 2*k;
            right = min(left+k,n);
        }
        return s;

    }
};