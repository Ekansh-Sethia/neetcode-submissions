class Solution {
private:
    void solve(vector<int> &nums, vector<vector<int>>& ans, vector<int>& out, int ind){
        if(ind >= nums.size()){
            ans.push_back(out);
            return;
        }

        //not pick
        solve(nums,ans,out,ind+1);
        //pick
        out.push_back(nums[ind]);
        solve(nums,ans,out,ind+1);
        out.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        solve(nums,ans,out,0);
        return ans;
    }
};
