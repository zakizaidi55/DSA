class Solution {
public:
    long long int MOD = 1000000007;  
    int solveUsingRecursion(int n, int k, int target, int diceUsed, int currSum) {
        
        if(diceUsed == n && currSum == target)
            return 1;
        
        if(diceUsed == n && currSum != target)
            return 0;
        
        if(currSum == target && diceUsed != n)
            return 0;
        
        int ans = 0;

        for(int face=1; face<=k; face++) {
            ans = ans + solveUsingRecursion(n, k, target, diceUsed+1, currSum+face);
        }

        return ans;
    }

    int solveUsingMem(int n, int k, int target, int diceUsed, int currSum, vector<vector<int> >&dp) {
        
        if(diceUsed == n && currSum == target)
            return 1;
        
        if(diceUsed == n && currSum != target)
            return 0;
        
        if(currSum == target && diceUsed != n)
            return 0;
        
        if(dp[diceUsed][currSum] != -1)
            return dp[diceUsed][currSum] ;
        

        int ans = 0;

        for(int face=1; face<=k; face++) {
            int recAns = 0;
            if(currSum + face <= target ) {
                recAns = solveUsingMem(n, k, target, diceUsed+1, currSum+face, dp);
            }
            ans = (ans % MOD +  recAns % MOD) % MOD;
        }

        dp[diceUsed][currSum]  = ans;
        return dp[diceUsed][currSum] ;
    }

    int solveUsingTabulation(int n, int k, int target) {
        vector<vector<int> >dp(n+1, vector<int>(target+1, 0));

        dp[n][target] = 1;
        for(int dice=n-1; dice>=0; dice--) {
            for(int sum=target; sum>=0; sum--) {
                int ans = 0;
                for(int face=1; face<=k; face++) {
                    int recAns = 0;
                    if(sum + face <= target ) {
                        recAns = dp[dice+1][sum+face];
                    }
                    ans = (ans % MOD +  recAns % MOD) % MOD;
                }

                dp[dice][sum]  = ans;
            }
        }

        return dp[0][0];
    }

    int solveUsingTabulationSO(int n, int k, int target) {
        // vector<vector<int> >dp(n+1, vector<int>(target+1, 0));
        vector<int>curr(target+1, 0);
        vector<int>next(target+1, 0);

        next[target] = 1;
        for(int dice=n-1; dice>=0; dice--) {
            for(int sum=target; sum>=0; sum--) {
                int ans = 0;
                for(int face=1; face<=k; face++) {
                    int recAns = 0;
                    if(sum + face <= target ) {
                        recAns = next[sum+face];
                    }
                    ans = (ans % MOD +  recAns % MOD) % MOD;
                }

               curr[sum]  = ans;
            }

            // shifting
            next = curr;
        }

        return curr[0];
    }

    int numRollsToTarget(int n, int k, int target) {
        int diceUsed = 0;
        int currSum = 0;
        // int ans = solveUsingRecursion(n, k, target, diceUsed, currSum);
        vector<vector<int> >dp(n+1, vector<int>(target+1, -1));
        // int ans = solveUsingMem(n, k, target, diceUsed, currSum, dp);
        int ans = solveUsingTabulationSO(n, k, target);
        return ans;
    }
};