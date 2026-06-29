class Solution {
    int n,m;
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>> &vis){
        int dr[] = {0,-1,0,1};
        int dc[] = {-1,0,1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nR = r + dr[i];
                int nC = c + dc[i];

                if(nR >= 0 && nC >= 0 && nR < n && nC < m 
                && !vis[nR][nC] && heights[nR][nC] >= heights[r][c]){
                    q.push({nR,nC});
                    vis[nR][nC] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false)), atl(n,vector<bool>(m,false));
        queue<pair<int,int>> pq, aq;

        for(int i = 0; i < n; i++){
            pac[i][0] = true;
            pq.push({i,0});

            atl[i][m-1] = true;
            aq.push({i,m-1});
        }
        for(int i = 0; i < m; i++){
            pac[0][i] = true;
            pq.push({0,i});

            atl[n-1][i] = true;
            aq.push({n-1,i});
        }

        bfs(heights,pq,pac);
        bfs(heights,aq,atl);

        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
