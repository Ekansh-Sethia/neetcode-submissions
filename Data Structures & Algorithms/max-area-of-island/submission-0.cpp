class Solution {
private:
    int bfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& vis){
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = true;
        q.push({row,col});
        int len = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!q.empty()){
            auto let = q.front();
            q.pop();
            len++;
            int r = let.first;
            int c = let.second;

            for(int i = 0; i < 4; i++){
                int nR = r + dr[i];
                int nC = c + dc[i];

                if(nR < n && nC < m && nR >= 0 && nC >= 0 
                && grid[nR][nC] == 1 && !vis[nR][nC]){
                    vis[nR][nC] = true;
                    q.push({nR,nC});
                }
            }
        }
        return len;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans = max(ans,bfs(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
};
