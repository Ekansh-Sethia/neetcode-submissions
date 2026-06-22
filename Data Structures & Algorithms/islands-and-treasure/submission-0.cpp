class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();     
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int dr[] = {0,-1,0,1};
            int dc[] = {1,0,-1,0};

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                        && grid[nr][nc] > grid[r][c] + 1){

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr,nc});
                }
            }
        }
    }
};
