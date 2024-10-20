class Solution {
public:
    char solve(vector<char> arr,char op) {
        if(op=='!') {
            return arr[0] == 't' ? 'f' : 't';
        }
        else if(op=='&') {
            return any_of(arr.begin(),arr.end(),[](char ch) {return ch=='f';}) ? 'f' : 't';
        }
        else { //for '|'
            return any_of(arr.begin(),arr.end(),[](char ch) {return ch=='t';}) ? 't' : 'f';
        }
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;
        for(int i=0;i<n;i++) {
            if(expression[i]==',') continue;
            if(expression[i]==')') {
                vector<char> arr;
                while(st.top() != '(') {
                    arr.push_back(st.top());
                    st.pop();
                }
                st.pop(); //pop the ')'
                char op = st.top();
                st.pop(); //pop the operator
                st.push(solve(arr,op));
            } else st.push(expression[i]);
        }
        return st.top() == 't' ? true : false;
    }
};