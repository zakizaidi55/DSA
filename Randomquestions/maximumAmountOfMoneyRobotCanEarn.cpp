class Solution {
public:
    int solveUsingMem(vector<vector<int>>& coins, int i, int j, int&m, int&n, int neu, vector<vector<vector<int> > >&dp) {
        if(i == m-1 && j == n-1) {
            // reach at last dest
            if(coins[i][j] < 0 && neu > 0) {
                return 0;
            }

            return coins[i][j];
        }

        if(i >= m || j >= n)
            return INT_MIN;

        if(dp[i][j][neu] != INT_MIN)
            return dp[i][j][neu];

        // take
        int take = coins[i][j] + max(solveUsingMem(coins, i+1, j, m, n, neu, dp), solveUsingMem(coins, i, j+1, m, n, neu, dp));

        // skip
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solveUsingMem(coins, i+1, j, m, n, neu-1, dp);
            int skipRight = solveUsingMem(coins, i, j+1, m, n, neu-1, dp);

            skip = max(skipDown, skipRight);
        }

        return dp[i][j][neu] = max(take, skip);
    }

    int solveUsingRec(vector<vector<int>>& coins, int i, int j, int m, int n, int neu) {
        if(i == m-1 && j == n-1) {
            // reach at last dest
            if(coins[i][j] < 0 && neu > 0) {
                return 0;
            }

            return coins[i][j];
        }

        if(i >= m || j >= n)
            return INT_MIN;

        // take
        int take = coins[i][j] + max(solveUsingRec(coins, i+1, j, m, n, neu), solveUsingRec(coins, i, j+1, m, n, neu));

        // skip
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solveUsingRec(coins, i+1, j, m, n, neu-1);
            int skipRight = solveUsingRec(coins, i, j+1, m, n, neu-1);

            skip = max(skipDown, skipRight);
        }

        return max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        int i = 0;
        int j = 0;
        int neu = 2;
        vector<vector<vector<int> > >dp(m+1, vector<vector<int> > (n+1, vector<int>(5, INT_MIN)));
        // return solveUsingRec(coins, i, j, m, n, neu);
        return solveUsingMem(coins, i, j, m, n, neu, dp);
    }
}; 


