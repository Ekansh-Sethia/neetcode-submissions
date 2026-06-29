class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        queue<pair<int,int>> q;

        q.push({0,-1});
        vis[0] = true;
        int cnt = 0;

        while(!q.empty()){
            int child = q.front().first;
            int parent = q.front().second;
            cnt++;
            q.pop();

            for(auto i : adj[child]){
                if(vis[i] && i != parent) return false;
                else if(!vis[i]){
                q.push({i,child});
                vis[i] = true;
                }
            }
        }
        return cnt == n;
    }
};
