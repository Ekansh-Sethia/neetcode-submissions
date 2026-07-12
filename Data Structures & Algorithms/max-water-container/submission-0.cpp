class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s = 0, e = heights.size() - 1;
        int ans = 0;
        while(s < e){
            ans = max(ans, min(heights[s],heights[e]) * (e-s));
            //cout<<heights[s]<<" "<< heights[e]<<" "<<ans<<endl;

            if(heights[s] < heights[e]) s++;
            else e--;
        }
        return ans;
    }
};
