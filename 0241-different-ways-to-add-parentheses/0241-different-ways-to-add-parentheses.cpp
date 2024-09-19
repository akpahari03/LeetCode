class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0;i<expression.length();i++) {
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*') {
                vector<int> left_ans = diffWaysToCompute(expression.substr(0,i));
                vector<int> right_ans = diffWaysToCompute(expression.substr(i+1));
                for(int &x : left_ans) {
                    for(int &y : right_ans) {
                        if(expression[i]=='+') ans.push_back(x+y);
                        else if(expression[i]=='-') ans.push_back(x-y);
                        else ans.push_back(x*y);
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(stoi(expression));
        return ans;
    }
};