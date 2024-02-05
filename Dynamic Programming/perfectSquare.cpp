class Solution {
public:
    int solveUsingRecu(int n) {
        // base case
        if(n == 0) {
            return 1;
        }

        if(n < 0) {
            // cout << "negative aa gya " << endl;
            return 0;
        }

        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;

        while(i <= end) { 
            int perfectSq = i*i;
            int numberOfPerfectSquare = 1 + solveUsingRecu(n - perfectSq);
           
            if(numberOfPerfectSquare < ans) {
                ans = numberOfPerfectSquare;
            }

            i++;
        }
        return ans;
    }

    int solveUsingMem(int n, vector<int>&dp) {
        // base case
        if(n == 0) {
            return 1;
        }

        if(n < 0) {
            // cout << "negative aa gya " << endl;
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;

        while(i <= end) { 
            int perfectSq = i*i;
            int numberOfPerfectSquare = 1 + solveUsingMem(n - perfectSq, dp);
           
            if(numberOfPerfectSquare < ans) {
                ans = numberOfPerfectSquare;
            }

            i++;
        }
        dp[n] = ans;
        return dp[n];
    }

    int solveUsingTab(int n) {
        vector<int>dp(n+1, -1);

        dp[0] = 1;
        
        for(int i=1; i<=n; i++) {
            int start = 1;
            int end = sqrt(i);
            int ans = INT_MAX;

            while(start <= end) { 
                int perfectSq = start*start;
                int numberOfPerfectSquare = 1 + dp[i - perfectSq];
            
                if(numberOfPerfectSquare < ans) {
                    ans = numberOfPerfectSquare;
                }

                start++;
            }
            dp[i] = ans;
            
        }

        return dp[n];

    }


    int numSquares(int n) {

        // return solveUsingRecu(n) - 1;
        vector<int>dp(n+1, -1);
        // return solveUsingMem(n, dp)-1;
        return solveUsingTab(n)-1;
    }
};