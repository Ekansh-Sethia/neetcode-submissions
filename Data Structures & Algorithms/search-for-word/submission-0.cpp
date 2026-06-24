class Solution {
private:
    bool find(vector<vector<char>>& board, int row, int col, string& word,
     int n, int m, int ind, string last){
        if(ind >= word.length()) return true;

        if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[ind]) return false;

        bool up = last == "down" ? false : find(board,row-1, col, word,n,m,ind+1,"up");
        bool down = last == "up" ? false : find(board,row+1,col,word,n,m,ind+1, "down");
        bool right = last == "left" ? false : find(board,row,col+1,word,n,m,ind+1, "right");
        bool left = last == "right" ? false : find(board,row,col-1,word,n,m,ind+1, "left");
        return (up||down||left||right);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(find(board,i,j,word,n,m,0,"")) return true;
                }
            }
        }
        return false;
    }
};
