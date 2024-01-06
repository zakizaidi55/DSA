class Solution {
public:
    int solveUsingRec(int n) {
        // base case
        if(n == 0 || n == 1) {
            return n;
        }

        int ans = fib(n-1) + fib(n-2);

        return ans;
    
    }

    // top down approach
    // rec + memoisation approach

    int solveUsigMem(int n, vector<int>&dp) {
        // base case
        if(n == 0 || n == 1) {
            return n;
        }

        // step3: if answer already exist then return 
        if(dp[n] != -1) {
            return dp[n];
        }
        
        // step2: store and return dp array
        dp[n] = solveUsigMem(n-1, dp) + solveUsigMem(n-2, dp);

        return dp[n];
    }

    // solve using tabulation method
    int solveUsingTab(int n) {
        // step1: create a dp array
        vector<int>dp(n+1, -1);

        // step2: analyse the base case and fil the dp array
        dp[0] = 0;
        if(n == 0) {
            return dp[0];
        }
        dp[1] = 1;

        // step3: fill the remaining dp array

        for(int i=2; i<=n;i++) {
            // copy paste the recursive relation
            // replace the recursive calls with dp array
            // make sure dp arrays is using looping variable "i"
            dp[i] = dp[i-1] + dp[i-2];
        }

        // return ans
        return dp[n];

    }

    // some spave optimisation
    int solveUsingTabSpaceOptimise(int n) {
        // step1: create a dp array
        // vector<int>dp(n+1, -1);

        // step2: analyse the base case and fil the dp array
        int prev = 0;
        if(n == 0) {
            return n;
        }

        if(n == 1) {
            return 1;
        }
        int curr = 1;

        // step3: fill the remaining dp array
        int ans;
        for(int i=2; i<=n;i++) {
            // copy paste the recursive relation
            // replace the recursive calls with dp array
            // make sure dp arrays is using looping variable "i"
            // dp[i] = dp[i-1] + dp[i-2];
            ans = curr + prev;

            // catch->important step bhul jate hai
            prev = curr;
            curr = ans;
        }

        // return ans
        return ans;
    }


    int fib(int n) {
        // int ans = solveUsingRec(n);
        // return ans;

        // step1: create DP array
        vector<int>dp(n+1, -1);
        // int ans = solveUsigMem(n, dp);
        int ans = solveUsingTab(n);
        return ans;
    }



};