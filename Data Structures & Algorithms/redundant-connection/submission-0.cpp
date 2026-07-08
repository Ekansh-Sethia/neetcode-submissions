class Solution {
private:
    int bfs(vector<unordered_set<int>>& adj, int n){
        queue<pair<int,int>> q;
        vector<int> vis(n+1,false);
        q.push({1,-1});
        vis[1] = true;

        int len = 0;

        while(!q.empty()){
            auto fr = q.front();
            len++;
            q.pop();
            int node = fr.first;
            int parent = fr.second;

            for(int i : adj[node]){
                if(!vis[i]){
                    q.push({i,node});
                    vis[i] = true;
                }
                else if(i != parent) return -1;
            }
        }
        return len;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> adj(n+1);
        for(auto i : edges){
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        // for(int i = 0; i <= n; i++){
        //     cout<<i<<" : ";
        //     for(auto j : adj[i]) {
        //         cout<<j<<" ";
        //     }cout<<endl;
        // }
        for(int i = n-1; i >= 0; i--){
            int f = edges[i][0];
            int s = edges[i][1];
            //cout<<f<<" "<<s<<endl;

            adj[f].erase(s);
            adj[s].erase(f);

            if(bfs(adj,n) == n) return {f,s};

            adj[f].insert(s);
            adj[s].insert(f);            
        }
        return {};
    }
};
