class Solution {
private:
    bool possible(vector<vector<string>>& out, int row, int col, int n){
        //col check
        int i = 0;
        while(i < n){
            if(out[i][col] == "Q") return false;
            i++;
        }

        //diagonal check
        int x,y;
        if(row > col) {
            y = 0, x = row-col;
        }
        else{
            x = 0, y = col-row;
        }
        while(x < n && y < n){
            if(out[x][y] == "Q") return false;
            x++, y++;
        }
        if(row + col >= n-1){
            x = n-1, y = row+col-x;
        }
        else{
            y = 0, x = row+col;
        }
        while(x >= 0 && y < n){
            if(out[x][y] == "Q") return false;
            x--;
            y++;
        }
        return true;
    }

    void storeAns(vector<vector<string>>& ans, vector<vector<string>>& out){
        vector<string> let;
        for(auto i : out){
            string temp = "";
            for(auto j : i) temp += j;
            let.push_back(temp);
        }
        ans.push_back(let);
    }
    void solve(vector<vector<string>>& ans, vector<vector<string>>& out, int n, int ind){
        if(ind >= n){
            storeAns(ans,out);
            return;
        }

        for(int i = 0; i < n; i++){
            if(possible(out,ind,i,n)){
                out[ind][i] = "Q";
                solve(ans,out,n,ind+1);
                out[ind][i] = ".";
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> out(n,vector<string>(n,"."));
        vector<vector<string>> ans;
        solve(ans,out,n,0);
        return ans;
    }
};
