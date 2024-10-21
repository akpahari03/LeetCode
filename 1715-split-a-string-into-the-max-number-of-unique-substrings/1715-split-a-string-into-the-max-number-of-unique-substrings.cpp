class Solution {
public:
    void solve(int i , string &s,unordered_set<string>& st,int currCount,int& maxCount) {
        if(i==s.length()) {
            maxCount = max(maxCount,currCount);
            return;
        }
        for(int j=i;j<s.length();j++) {
            string sub = s.substr(i,j-i+1);
            if(st.find(sub) == st.end()) {
                st.insert(sub);
                solve(j+1, s, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount = 0;
        int currCount = 0;
        int i = 0;
        solve(i,s,st,currCount,maxCount);
        return maxCount;
    }
};