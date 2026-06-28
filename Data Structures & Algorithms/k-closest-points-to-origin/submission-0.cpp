class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(auto i : points){
            vector<int> let(3);
            let[1] = i[0];
            let[2] = i[1];
            let[0] = let[1]*let[1] + let[2]*let[2];
            pq.push(let);
        }
        while(pq.size() > k){
            pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();

            vector<int> temp(2);
            temp[0] = i[1];
            temp[1] = i[2];
            ans.push_back(temp);
        }
        return ans;
    }
};
