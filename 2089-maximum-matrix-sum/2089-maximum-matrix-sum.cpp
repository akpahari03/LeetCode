class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        long long negNos = 0;
        long long mini = pow(10,5);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                long long temp = matrix[i][j];
                sum += abs(temp);
                if(temp<0) negNos++;
                mini = min(mini,abs(temp));
            }
        }
        if(negNos%2!=0) {
            sum -= 2*mini;
        }
        return sum;
    }
};