class Solution {
public:
    int solve(int b ,int a ,string s) {
        if(s=="+") return a+b;
        else if(s=="-") return a-b;
        else if(s=="*") return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &s : tokens) {
            if(s=="+" || s=="-" || s=="/" || s=="*") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(solve(b,a,s));
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};