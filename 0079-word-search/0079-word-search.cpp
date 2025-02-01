class Solution {
public:
    bool solve(vector<vector<char>>& board,string& word,int i,int j,int idx,vector<vector<bool>>&vis) {
        //base case
        if(idx==word.length()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() ||
        vis[i][j] || board[i][j] != word[idx]) return false;

        vis[i][j] = true;
        if (solve(board, word, i + 1, j, idx + 1, vis) || 
            solve(board, word, i - 1, j, idx + 1, vis) || 
            solve(board, word, i, j + 1, idx + 1, vis) || 
            solve(board, word, i, j - 1, idx + 1, vis)) return true;

        vis[i][j] = false;  
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==word[0]) {
                    if(solve(board,word,i,j,0,vis)) return true;
                }
            }
        }
        return false;
    }
};