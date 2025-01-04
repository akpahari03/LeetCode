class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> letters;
        for(char &ch : s) {
            letters.insert(ch);
        }
        int count=0;
        for(char letter : letters) {
            int left_idx = -1;
            int right_idx = -1;
            for(int i=0;i<n;i++) {
                if(s[i]==letter) {
                    if(left_idx==-1) left_idx = i;
                    right_idx = i;
                }
            }
            unordered_set<char> st;
            for(int middle=left_idx+1;middle<right_idx;middle++) {
                st.insert(s[middle]);
            }
            count += st.size();
        }
        return count;
    }
};