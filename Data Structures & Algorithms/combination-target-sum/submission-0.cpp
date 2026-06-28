class Solution {
private:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& out, int ind){
        if(target == 0){
            ans.push_back(out);
            return;
        }
        if(target < 0 || ind >= nums.size()) return;

        out.push_back(nums[ind]);
        solve(nums,target-nums[ind], ans, out, ind);
        out.pop_back();
        solve(nums,target, ans, out, ind+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> out;

        solve(nums,target,ans,out,0);
        return ans;
    }
};
