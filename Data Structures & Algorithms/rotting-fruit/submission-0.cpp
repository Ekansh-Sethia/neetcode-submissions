class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>, int>> q;
        int time = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                    cnt++;
                }
                else if(grid[i][j] == 1) cnt++;
            }
        }
        int dr[] = {0,-1,0,1};
        int dc[] = {-1,0,1,0};
        int let = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int len = q.front().second;
            let++;
            if(len > time) time = len;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nR = r + dr[i];
                int nC = c + dc[i];
                if(nR >= 0 && nC >= 0 && nR < n && nC < m
                && !vis[nR][nC] && grid[nR][nC] == 1){
                    grid[nR][nC] = 2;
                    vis[nR][nC] = true;
                    q.push({{nR,nC}, len+1});
                }
            }
        }
        //cout<<let<<" "<< cnt<<" ";
        if(let == cnt) return time;
        return -1;
    }
};
