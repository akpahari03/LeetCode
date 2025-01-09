class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.length();
        int count = 0;
        for(int i=0;i<n;i++) {
            if(m>words[i].length()) continue;
            if(words[i].substr(0,m)==pref) count++;
        }
        return count;
    }
};