class Solution {
public:
    int MOD = 1e9+7;
    int solveUsingRec(int n, int x, int num) {
        // base case
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        // take the current number to the power x
        int currentPowerValue = pow(num, x);
        if(currentPowerValue > n)
            return 0;
        int take = solveUsingRec(n-currentPowerValue, x, num+1);
        int notTake = solveUsingRec(n, x, num+1);

        return take+notTake;
    }

    int solveUsingMem(int n, int x, int num, vector<vector<int> >&dp) {
        // base case
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        
        if(dp[n][num] != -1)
            return dp[n][num];
        // take the current number to the power x
        int currentPowerValue = pow(num, x);
        if(currentPowerValue > n)
            return 0;
        
        int take = solveUsingMem(n-currentPowerValue, x, num+1, dp);
        int notTake = solveUsingMem(n, x, num+1, dp);

        dp[n][num] = (take+notTake)%MOD;
        return dp[n][num];
    }

    int numberOfWays(int n, int x) {
        int num = 1;
        vector<vector<int> >dp(n+1000, vector<int>(n+1000, -1));
        // return solveUsingRec(n, x, num);
        return solveUsingMem(n, x, num, dp);
    }
};


