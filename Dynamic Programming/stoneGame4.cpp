class Solution {
public:
    bool solveUsingRec(int n) {
        if(n == 0) {
            // iska matlab jiski chance hai, wo har gya hai
            return false;
        } 

        for(int k=1; k*k<=n; k++) {
            if(solveUsingRec(n-k*k) == false) {
                // yeh bob chalega chance or agar uska false aagya toh, alice jit gya
                return true;
            }
        }

        return false;
    }


    bool solveUsingMem(int n, vector<int>&dp) {
        if(n == 0) {
            // iska matlab jiski chance hai, wo har gya hai
            return false;
        } 

        if(dp[n] != -1) 
            return dp[n];

        for(int k=1; k*k<=n; k++) {
            if(solveUsingMem(n-k*k, dp) == false) {
                // yeh bob chalega chance or agar uska false aagya toh, alice jit gya
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int>dp(n+1, -1);
        // return solveUsingRec(n);     
        return solveUsingMem(n, dp);      
    }
};

