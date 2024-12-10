class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        vector<vector<int>> matrix(26,vector<int>(n+1,0));

        char prev_char = s[0];
        int length = 0;
        for(int i=0;i<n;i++) {
            char curr_char = s[i];

            if(curr_char == prev_char) {
                length += 1;
                matrix[curr_char-'a'][length] += 1;
            } else {
                length = 1;
                matrix[curr_char-'a'][length] += 1;
                prev_char = curr_char;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++) {
            int cumSum = 0;
            for(int j=n;j>=1;j--) {
                cumSum += matrix[i][j];
                if(cumSum >=3) {
                    ans = max(ans,j);
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};