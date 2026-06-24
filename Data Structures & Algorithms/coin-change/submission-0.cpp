class Solution {
private:
    long long int solve(vector<int>& coins, int amount, int n, int ind, vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0 || ind >= n) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];

        long long int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + solve(coins,amount-coins[ind], n, ind,dp);
        long long int notTake = solve(coins, amount, n, ind+1,dp);

        return dp[amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1, -1);
        int let = solve(coins,amount,n,0,dp);
        if(let == INT_MAX) return -1;
        return let;
    }
};
