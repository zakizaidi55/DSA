class Solution {
public:
    int solveUsingRec(vector<int>&prefixSum, int index) {
        // base case
        if(index == prefixSum.size()-1)
            return prefixSum[index]; 

        // iska matlab alice ne iss index tak le liya ab bob ka minus karna hai
        int take = prefixSum[index] - solveUsingRec(prefixSum , index+1);

        // iska matlab abhi alice ne nhi liya hai wo aage jayega
        int skip = solveUsingRec(prefixSum, index+1);


        return max(take, skip);

    }

    int solveUsingMem(vector<int>&prefixSum, int index, vector<int>&dp) {
        // base case
        if(index == prefixSum.size()-1)
            return prefixSum[index]; 
        
        if(dp[index] != -1)
            return dp[index];

        // iska matlab alice ne iss index tak le liya ab bob ka minus karna hai
        int take = prefixSum[index] - solveUsingMem(prefixSum , index+1, dp);

        // iska matlab abhi alice ne nhi liya hai wo aage jayega
        int skip = solveUsingMem(prefixSum, index+1, dp);

        return dp[index] = max(take, skip);

    }

    int solveUsingTab(vector<int>&prefixSum, int index) {
        int n = prefixSum.size();
        vector<int> dp(n, 0);
        // Base case
        dp[n-1] = prefixSum[n-1];

        for(int i=n-2; i>=0; i--) {
            int take = prefixSum[i] - dp[i+1];

            // iska matlab abhi alice ne nhi liya hai wo aage jayega
            int skip = dp[i+1];

            dp[i] = max(take, skip);
        }

        return dp[index];
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>prefixSum(n, 0);

        prefixSum[0] = stones[0];

        for(int i=1; i<n; i++) {
            prefixSum[i] = stones[i] + prefixSum[i-1];
        }   

        vector<int>dp(n+1, -1);
        // return solveUsingRec(prefixSum, 1);
        // return solveUsingMem(prefixSum, 1, dp);
        return solveUsingTab(prefixSum, 1);
    }
};


