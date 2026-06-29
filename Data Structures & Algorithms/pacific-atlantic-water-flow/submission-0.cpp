class Solution {
    int n, m;
private:
    bool pacific(vector<vector<int>>& heights, int row, int col){
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[row][col] = true;
        q.push({row,col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r == 0 || c == 0) return true;
            int dr[] = {0,-1,0,1};
            int dc[] = {-1,0,1,0};

            for(int i = 0; i < 4; i++){
                int nR = r+dr[i];
                int nC = c+dc[i];

                if(nR >= 0 && nR < n && nC >= 0 && nC < m 
                && !vis[nR][nC] && heights[nR][nC] <= heights[r][c]){
                    q.push({nR,nC});
                    vis[nR][nC] = true;
                }
            }
        }
        return false;
    }
    bool atlantic(vector<vector<int>>& heights, int row, int col){
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[row][col] = true;
        q.push({row,col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r == n-1 || c == m-1) return true;
            int dr[] = {0,-1,0,1};
            int dc[] = {-1,0,1,0};

            for(int i = 0; i < 4; i++){
                int nR = r+dr[i];
                int nC = c+dc[i];

                if(nR >= 0 && nR < n && nC >= 0 && nC < m 
                && !vis[nR][nC] && heights[nR][nC] <= heights[r][c]){
                    q.push({nR,nC});
                    vis[nR][nC] = true;
                }
            }
        }
        return false;

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        n = heights.size(), m = heights[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific(heights,i,j) && atlantic(heights,i,j)) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
