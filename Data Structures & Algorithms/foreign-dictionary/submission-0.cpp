class Solution {
bool topoSort(stack<char> &st, vector<vector<char>>& adj, char start, vector<int>& vis){
    vis[start - 'a'] = 1;

    for(auto i : adj[start - 'a']){
        if(vis[i - 'a'] == 1) return false;

        else if (vis[i-'a'] == 0){
            if(!topoSort(st, adj, i,vis)) return false;
        }
    }

    vis[start- 'a'] = 2;
    st.push(start);
    return true;
}
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<char>> adj(26);
        char start = '\0';
        for(int i = 0; i < n-1; i++){
            int j = 0;
            int len = min(words[i].length(),words[i+1].length());
            while(j < len && words[i][j] == words[i+1][j]){
                j++;
            }
            if (j == len) {
                if (words[i].length() > words[i+1].length())
                    return "";
                continue;
            }
            adj[words[i][j] - 'a'].push_back(words[i+1][j]);
        }
        
        vector<int> present(26, 0);

        for (auto &w : words)
            for (char c : w)
                present[c - 'a'] = 1;
        // for(int i = 0; i < 26; i++){
        //     if(!adj[i].empty()){
        //         cout<< (char)('a'+i) <<" : ";
        //         for(auto j : adj[i]) cout<<j<<" ";
        //         cout<<endl;
        //     }
        // }

        stack<char> st;
        vector<int> vis(26,0);
        for(int i = 0; i < 26; i++){
            if(present[i] && !vis[i]){
                if(!topoSort(st, adj, 'a' + i, vis))
                    return "";
        }
}
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
