class Solution {
private:
    void solve(vector<int>& nums, int target, int &ans, int ind){
        if(ind >= nums.size()){
            if(target == 0) ans++;
            return;
        }
        solve(nums,target-nums[ind],ans,ind+1);
        solve(nums,target+nums[ind],ans,ind+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        solve(nums,target,ans,0);
        return ans;
    }
};
