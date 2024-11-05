class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int changes = 0;
        int count = 0;

        char ch = s[0];
        for(int i=0;i<n;i++) {
            if(ch==s[i]) {
                count++;
                continue;
            }
            if(count%2==0) {
                count = 1;
            }
            else {
                changes += 1;
                count = 0;
            }
            ch = s[i];
        }
        return changes;
    }
};