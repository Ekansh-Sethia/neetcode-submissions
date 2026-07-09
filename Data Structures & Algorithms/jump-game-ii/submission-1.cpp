class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>> q;
        int n = nums.size();
        vector<bool> vis(n,false);
        vis[0] = true;

        q.push({0,0});
        
        while(!q.empty()){
            int ind = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(ind == n-1) return dist;

            for(int i = 1; i <= nums[ind]; i++){
                if(ind + i < n && !vis[ind+i]){
                    q.push({ind+i,dist+1});
                    vis[ind+i] = true;
                }
            }
        }
        return -1;
    }
};
