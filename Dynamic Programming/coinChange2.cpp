class Solution {
public:
    int solve(int amount,vector<int>&coins,int n){
        if(n==0)
            return(amount%coins[0]==0);
        int include = 0;
        if(coins[n] <= amount)
            include = solve(amount-coins[n],coins,n);

        int exclude = solve(amount,coins,n-1);

        return (include+exclude);
    }
    int solveUsingMem(int amount,vector<int>&coins,int n,vector<vector<int>>&dp){
       if(n==0)
            return(amount%coins[0]==0);
       if(dp[n][amount]!=-1)
            return dp[n][amount];
       int include=0;

       if(coins[n]<=amount)
            include=solveUsingMem(amount-coins[n],coins,n,dp);
            
       int exclude=solveUsingMem(amount,coins,n-1,dp);

       return dp[n][amount]=(include+exclude);
    }
    int change(int amount, vector<int>& coins) {
        //  return solve(amount,coins,coins.size()-1);
        //  memoization
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solveUsingMem(amount,coins,coins.size()-1,dp);
    }
};