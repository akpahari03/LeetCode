class Solution {
public:
    bool check(stack<char>& st,string& part ,int m) {
        stack<char> tempSt = st;
        for(int idx=m-1 ;idx>=0 ;idx--) {
            if(tempSt.top() != part[idx]) {
                return false;
            }
            tempSt.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.length();
        int m = part.length();

        for(int i=0;i<n;i++) {
            st.push(s[i]);

            if(st.size() >= m && check(st,part,m)==true) {
                for(int j=0;j<m;j++) {
                    st.pop();
                }
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};