class Solution {
public:
    int solve(int n) {
        int sum = 0;
        while(n>0) {
            int digit = n%10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = solve(n);
        }
        return n==1;
    }
};