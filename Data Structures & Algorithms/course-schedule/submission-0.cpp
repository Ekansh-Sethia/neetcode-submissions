class Solution {
private:
    bool cycle(vector<vector<int>> &adj, int i, vector<bool> &vis, vector<bool>& pathVis){
        vis[i] = true;
        pathVis[i] = true;
        for(auto j : adj[i]){
            if(!vis[j]){
                return cycle(adj,j,vis,pathVis);
            }
            else if(vis[j] && !pathVis[j]) continue;
            else return true;
        }
        pathVis[i] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(numCourses,false), pathVis(numCourses,false);
        for(int i = 0; i < numCourses; i++){
            if(cycle(adj,i,vis,pathVis)) return false;
        }
        return true;
    }
};
