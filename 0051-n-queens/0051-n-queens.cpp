class Solution {
public:
    void addSolution(vector<vector<string> > &ans,vector<vector<int> >& board,int n) {
	vector<string> temp;
	for(int i=0;i<n;i++) {
        string row = "";
		for(int j=0;j<n;j++) {
            if(board[i][j]==1) {
                row += 'Q';
            }
            else row += '.';
		}
        temp.push_back(row);
	}
	ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<int> >& board,int n) {
	int x = row;
	int y = col;

	//checking for same row
	while(y>=0) {
		if(board[x][y]==1) return false;
		y--;
	}
	x=row;
	y=col;
	//checking for diagonal
	while(x>=0 && y>=0) {
		if(board[x][y]==1) return false;
		y--;
		x--;
	}
	x=row;
	y=col;
	//checking for diagonal
	while(x<n && y>=0) {
		if(board[x][y]==1) return false;
		y--;
		x++;
	}
	return true;
}
void solve(int col,vector<vector<string> >& ans,vector<vector<int> >& board,int n) {
	//base case
	if(col==n) {
		addSolution(ans,board,n);
		return;
	}

	for(int row=0;row<n;row++) {
		if(isSafe(row,col,board,n)) {
			board[row][col] = 1;
			solve(col+1,ans,board,n);
			//backtracking
			board[row][col] = 0;
		}
	}
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<string>> ans;
        solve(0,ans,board,n);

        return ans;
    }
};