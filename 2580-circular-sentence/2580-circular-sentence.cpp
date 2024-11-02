class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if(sentence[0] != sentence[n-1]) return false;
        int i = 0;
        while(i<n) {
            while(i<n && sentence[i] != ' ') i++;
            if(i<n && sentence[i-1] != sentence[i+1]) return false;
            i++;
        }
        return true;
    }
};