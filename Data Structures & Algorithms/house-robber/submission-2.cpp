class Solution {
private:
    int solve(vector<int>& nums, int ind, vector<int>& dp){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(nums,ind-2, dp);
        int notPick = solve(nums,ind-1, dp);

        return dp[ind] = max(pick,notPick);
    }
    int tabulation(vector<int> &nums, int n){
        vector<int> dp(n,0);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            int pick = i >= 2 ? nums[i] + dp[i-2] : 0;
            int notPick = dp[i-1];

            dp[i] = max(pick,notPick);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return tabulation(nums,n);
    }
};
