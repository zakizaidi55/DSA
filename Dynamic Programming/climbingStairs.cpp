class Solution {
public:
    int solveUsingRec(int n) {
        if(n == 0)
            return 1;
        
        if(n == 1)
            return 1;
        
        int ans = solveUsingRec(n-1) + solveUsingRec(n-2);

        return ans;
    }

    int solveUsingMem(int  n, vector<int>& dp) {
        if(n == 0)
            return 1;
        
        if(n == 1)
            return 1;
        
        //step3:  if ans exist then return it
        if(dp[n] != -1) {
            return dp[n];
        }
        
        // step2: store the ans and return
        dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);

        return dp[n];
    }

    int solveUsingTab(int n) {
        // step1: create a dp array
        vector<int>dp(n+1, -1);

        // step2: analyse the base case and fill the dp array
        dp[0] = 1;
        dp[1] = 1;

        // step3: fill the remainig dp array

        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }

    int climbStairs(int n) {
        // step1: create a DP array
        vector<int>dp(n+1, -1);
        // int ans = solveUsingRec(n);
        // int ans = solveUsingMem(n, dp);
        int ans = solveUsingTab(n); 
        return ans;
    }
};