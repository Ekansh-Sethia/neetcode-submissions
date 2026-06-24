class Solution {
private:
    bool find(vector<vector<char>>& board, int row, int col, string& word,
     int n, int m, int ind){
        if(ind >= word.length()) return true;

        if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[ind]) return false;
        char ch = board[row][col];
        board[row][col] = '#';
        bool up = find(board,row-1, col, word,n,m,ind+1);
        bool down = find(board,row+1,col,word,n,m,ind+1);
        bool right = find(board,row,col+1,word,n,m,ind+1);
        bool left = find(board,row,col-1,word,n,m,ind+1);

        board[row][col] = ch;
        return (up||down||left||right);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(find(board,i,j,word,n,m,0)) return true;
                }
            }
        }
        return false;
    }
};
