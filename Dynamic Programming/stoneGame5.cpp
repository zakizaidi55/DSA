class Solution {
public:
    int solveUsingRec(int l, int r, vector<int>&prefixSum) {
        if(l >= r)
            return 0;
        
        int score = 0;
        for(int mid=l; mid<=r-1; mid++) {
            int leftScore = prefixSum[mid] - (l > 0 ? prefixSum[l-1]: 0);
            int rightScore = prefixSum[r] - prefixSum[mid];

            if(leftScore < rightScore) {
                score = max(score, leftScore + solveUsingRec(l, mid, prefixSum));
            }

            else if(leftScore > rightScore) {
                score = max(score, rightScore + solveUsingRec(mid+1, r, prefixSum));
            }

            else {
                // leftScore == rightScore
                score = max({score, leftScore + solveUsingRec(l, mid, prefixSum), rightScore + solveUsingRec(mid+1, r, prefixSum)});
            }

        }

        return score;
    }

    int solveUsingMem(int l, int r, vector<int>&prefixSum, vector<vector<int>>&dp) {
        if(l >= r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];

        int score = 0;
        for(int mid=l; mid<=r-1; mid++) {
            int leftScore = prefixSum[mid] - (l > 0 ? prefixSum[l-1]: 0);
            int rightScore = prefixSum[r] - prefixSum[mid];

            if(leftScore < rightScore) {
                score = max(score, leftScore + solveUsingMem(l, mid, prefixSum, dp));
            }

            else if(leftScore > rightScore) {
                score = max(score, rightScore + solveUsingMem(mid+1, r, prefixSum, dp));
            }

            else {
                // leftScore == rightScore
                score = max({score, leftScore + solveUsingMem(l, mid, prefixSum, dp), rightScore + solveUsingMem(mid+1, r, prefixSum, dp)});
            }

        }

        return dp[l][r] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>prefixSum(n, 0);
        prefixSum[0] = stoneValue[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + stoneValue[i];
        }

        vector<vector<int> >dp(n+1, vector<int>(n+1, -1));

        // return solveUsingRec(0, n-1, prefixSum);
        return solveUsingMem(0, n-1, prefixSum, dp);
    }
};


