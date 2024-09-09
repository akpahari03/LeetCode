class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        int top = 0;
        int left = 0;
        int right = n-1;
        int down = n-1;

        int total = n*n;
        int count = 0;
        int temp = 1;
        
        while(count<total) {
            for(int i=left ; i<=right && count<total ; i++) {
                matrix[top][i]= temp;
                temp++;
                count++;
            }
            top++;
            for(int i=top ; i<=down && count<total ; i++) {
                matrix[i][right] = temp;
                temp++;
                count++;
            }
            right--;
            for(int i=right;i>=left && count<total ; i--) {
                matrix[down][i] = temp;
                temp++;
                count++;
            }
            down--;
            for(int i=down;i>=top && count<total;i--) {
                matrix[i][left] = temp;
                temp++;
                count++;
            }
            left++;
        }
        return matrix;
    }
};