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

    int tabulation(vector<int>& coins, int amount, int n){
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                long long int pick = i - coins[j] >= 0 && dp[i-coins[j]] != INT_MAX ? dp[i-coins[j]] + 1 : INT_MAX;
                long long int notPick = dp[i];

                dp[i] = min(pick,notPick);
            }
        }
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int let = tabulation(coins,amount,n);
        if(let == INT_MAX) return -1;
        return let;
    }
};
