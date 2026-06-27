class Solution {
private:
    bool cycle(vector<vector<int>> &adj, int i, vector<bool> &vis, vector<bool>& pathVis){
        vis[i] = true;
        pathVis[i] = true;
        for(auto j : adj[i]){
            if(!vis[j]){
                if(cycle(adj,j,vis,pathVis)) return true;
            }
            else if(vis[j] && !pathVis[j]) continue;
            else return true;
        }
        pathVis[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& adj) {
        vector<bool> vis(numCourses,false), pathVis(numCourses,false);
        for(int i = 0; i < numCourses; i++){
            if(cycle(adj,i,vis,pathVis)) return false;
        }
        return true;
    }
    void dfs(vector<vector<int>> &adj, int i, stack<int>& st, vector<bool>& vis){
        vis[i] = true;

        for(int j : adj[i]){
            dfs(adj,j,st,vis);
        }

        st.push(i);
    }
    void topoSort(vector<vector<int>>& adj, stack<int>& st, int numCourses){
        vector<bool> vis(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                dfs(adj,i,st,vis);
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        if(!canFinish(numCourses,adj)) return {};
        else{
            stack<int> st;
            topoSort(adj,st,numCourses);
            vector<int> ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }
    }
};
