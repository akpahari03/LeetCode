class Solution {
public:
    bool isValid()
    bool isPalindrome(string s) {
        string temp = "";
        for(char& ch : s) {
            if(valid(ch)) temp.push_back(ch);
        }
    }
};