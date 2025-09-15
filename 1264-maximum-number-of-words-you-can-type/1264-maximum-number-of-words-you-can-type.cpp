class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool temp[26] = {false};
        for(char &ch : brokenLetters) {
            temp[ch-'a'] = true;
        }
        
        bool canType = true;
        int result = 0;
        for(char &ch : text) {
            if(ch==' ') {
                if(canType) result++;
                canType = true;
            }
            else if(temp[ch-'a']) {
                canType = false;
            }
        }
        if(canType) result++;
        return result;


    }
};