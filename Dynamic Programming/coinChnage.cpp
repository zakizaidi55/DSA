class Solution {
public:
    int solveUsingRec(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        
        if(amount < 0)
            return INT_MAX;
        
        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++) {
            int currCoin = coins[i];

            if(currCoin <= amount) {
                int recAns = solveUsingRec(coins, amount-currCoin);
                if(recAns != INT_MAX) {
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }
            }
        }

        return mini;
    }

    // solve using memoisation
    int solveUsingMem(vector<int>& coins, int amount, vector<int>&dp) {
        if(amount == 0)
            return 0;

        // if anwer already exist
        if(dp[amount] != -1) {
            return  dp[amount];
        }


        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++) {
            int currCoin = coins[i];

            if(amount - currCoin >= 0) {
                int recAns = solveUsingMem(coins, amount-currCoin, dp);
                if(recAns != INT_MAX) {
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }
            }
        }

        dp[amount] = mini;
        return  dp[amount];
    }

    int solveUsingTabulation(vector<int>& coins, int amount) {
        int n = amount;
        vector<int>dp(n+1, INT_MAX);

        dp[0] = 0;

        for(int value=1; value<=amount; value++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
                int currCoin = coins[i];

                if(value - currCoin >= 0) {
                    int recAns = dp[value - currCoin];
                    if(recAns != INT_MAX) {
                        int ans = 1 + recAns;
                        mini = min(mini, ans);
                    }
                }
            }

            dp[value] = mini;
        }

        return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        // step1: create a DP array
        // int n = amount;
        // vector<int>dp(n+1, -1);
        // int ans = solveUsingRec(coins, amount);

        // int ans = solveUsingMem(coins, amount, dp);
        int ans = solveUsingTabulation(coins, amount);
        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};