class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int original = x;
        int digit;
        int reversed = 0;
        while (x != 0) {
            if(reversed > INT_MAX/10 || reversed < INT_MIN/10)
            {
               return 0;
            }
            digit=x%10;
            reversed = reversed * 10 + digit; ;
            x /= 10;
        }

        if(original==reversed) return true;
        else return false;
    }
};