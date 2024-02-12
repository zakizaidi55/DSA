class Solution {
public:
    int solveUsingRecursion(int n) {
        if(n == 0 )
            return 0;
        
        if(n == 1)
            return 1;
        
        if(n == 2)
            return 1;
        
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2) + solveUsingRecursion(n-3);
        

        return ans;

    }

    int solveUsingMem(int n, vector<int>& dp) {
        if(n == 0 )
            return 0;
        
        if(n == 1)
            return 1;
        
        if(n == 2)
            return 1;

        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int ans = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp) + solveUsingMem(n-3, dp);

        dp[n] = ans;

        return dp[n];
        
    }
    int tribonacci(int n) {
        
        vector<int>dp(n+1, -1);
        // return solveUsingRecursion(n);
        return solveUsingMem(n, dp);
    }
};