class Solution {
public:
    int solveUsingRec(int n, vector<int>& costs, int index) {
        if(index >= costs.size()) {
            return 0;
        }
        
        int cost = INT_MAX;
        int j = index+1;
        if(j <= n) {
            cost = costs[j-1] + (j-index) * (j-index) + solveUsingRec(n, costs, j);
        }

        j = index+2;
        if(j <= n) {
            cost = min(cost, costs[j-1] + (j-index) * (j-index) + solveUsingRec(n, costs, j));
        }   

        j = index+3;
        if(j <= n) {
            cost = min(cost, costs[j-1] + (j-index) * (j-index) + solveUsingRec(n, costs, j));
        }

        return cost;
    }

    int solveUsingMem(int n, vector<int>& costs, int index, vector<int>&dp) {
        if(index >= costs.size()) {
            return 0;
        }

        if(dp[index] != -1)
            return dp[index];
        
        int cost = INT_MAX;
        int j = index+1;
        if(j <= n) {
            cost = costs[j-1] + (j-index) * (j-index) + solveUsingMem(n, costs, j, dp);
        }

        j = index+2;
        if(j <= n) {
            cost = min(cost, costs[j-1] + (j-index) * (j-index) + solveUsingMem(n, costs, j, dp));
        }   

        j = index+3;
        if(j <= n) {
            cost = min(cost, costs[j-1] + (j-index) * (j-index) + solveUsingMem(n, costs, j, dp));
        }

        return dp[index] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        int index = 0;
        int currCost = 0;
        vector<int>dp(n+1, -1);
        // return solveUsingRec(n, costs, index);
        return solveUsingMem(n, costs, index, dp);
    }
};


